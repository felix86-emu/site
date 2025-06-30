---
layout: post
title: felix86 25.07
---

Another month has passed, and felix86 development continues!

# AAA games

Some AAA games are now playable! Titles include Linux games like Witcher 2, but also Windows games like Witcher 3 and Crysis!

<img src="{{ site.baseurl }}/images/crysis.png" width="800" style="display: block; margin: 10px auto"/>
_Non-trivial Windows games would not work with the previous version_

These just started working, so we haven't had enough time to profile or optimize them yet. So don’t expect great performance yet!

<img src="{{ site.baseurl }}/images/witcher3.png" width="800" style="display: block; margin: 10px auto"/>
_Witcher 3 on Milk-V Jupiter_

## User-friendliness

The recommended way of using felix86 now is through the emulated bash.

To do so, install felix86 using the installation script (or register it with binfmt_misc using `sudo -E felix86 -b`), then run the x86-64 version of bash:
```
FELIX86_QUIET=1 felix86 /bin/bash
```

This should start an instance of the emulated bash that is now inside the rootfs. You can use it to run your games.

To learn more, [check out the updated usage guide](https://github.com/OFFTKP/felix86/blob/master/docs/how-to-use.md).


## AppImage support

AppImages had a permission issue - basically they would try to run a privileged app like `mount`, but when this was run through the emulator, the emulator would not inherit the privileges.

Since we now install felix86 in binfmt_misc, the emulator should inherit the setuid bit of these apps, and AppImage executables should now work!

## Better filesystem emulation

We try to restrict all guest file accesses inside the rootfs. In recent PRs we improved a few things.

`/dev`, `/proc`, `/sys`, `/run` and `/tmp` were symlinks. The reason for this is that mounting requires superuser privileges. Using namespaces doesn't cut it, because then we wouldn't be able to run apps like `sudo` or `mount`. Additionally, using namespaces to get mount privileges means that other instances of felix86 won't see the same mounts as that instance.

But symlinks have their own set of problems.  For example, `readlink(/proc)` would be equal to `/proc`, causing recursion in the guest. This was previously solved by detecting accesses to `/proc` (and the others) and redirecting them to the host `/proc`. All in all, it was hacky and horrible.

We now use a separate executable, called `felix86-mounter`. The installation script will install it and give it special privileges. Then, felix86 will call `felix86-mounter` with the rootfs path as the argument. `felix86-mounter` will then do a few things:
- Create a temporary dir called `/run/felix86/mounts/mount-XXXXXX` (where the X's are random using `mkdtemp`)
- Create a file that has the actual rootfs path in `/run/felix86/mounts/mount-XXXXXX/path.txt`
- Create a directory `/run/felix86/mounts/mount-XXXXXX/rootfs`
- Mount the rootfs there (this is good because now the rootfs itself is a mount, just like `/` is)
- Mount the necessary dirs (`/dev`, `/proc`, ...) inside the rootfs
- Return the `/run/felix86/mounts/mount-XXXXXX/rootfs` path

Further runs of `felix86-mounter` will detect that a mounted path already exists using the `path.txt` file.

This is better than doing it on the felix86 executable:
- If we did this inside the felix86 executable itself, it would need special permissions which is definitely scarier if we don't properly drop them after mounting
- The felix86 executable frequently changes and needs to be given permissions again, felix86-mounter will not
- Having to run sudo everytime you want to run felix86 would be clunky
- Having to run sudo on anything you attach to felix86 (gdb, strace, ...) would also suck

## Symlink resolving

We had a bug in our previous implementation, which happened to go undetected:

The symlink syscall would resolve the old path to be inside the rootfs. For example, if you ran `symlink(/oldpath, /linktarget)`, `/linktarget` would now resolve to `/path/to/rootfs/oldpath`.

This would work with *most applications*. However, as we start to worry about programs calling `chroot` and changing our root, this is no longer a viable solution.

Symlink shouldn't resolve the old path to be inside the rootfs. But if we don't do that, then we need to resolve paths ourselves using the [same algorithm the kernel uses](https://man7.org/linux/man-pages/man7/path_resolution.7.html), while placing results in the rootfs. This is difficult to implement while avoiding potential bugs.

Luckily, the `openat2` syscall has a flag called `RESOLVE_IN_ROOT`. This is perfect for our use case, as it can open a file while resolving symlinks to be inside a file descriptor -- our rootfs file descriptor. We can then readlink the `/proc/self/fd/<fd>` to get the absolute resolved path that is inside the rootfs.

This also helps with containerization, as it makes it harder for programs to escape the rootfs. felix86 isn't a security application and should only be used with trusted programs, but some programs would do stuff like `fd = open("/")`, `openat(fd, "..")` and depend on the file descriptors being the same, which we previously had to hack around.

---

Thanks for reading the July post!

It was an exciting month for felix86 progress. See you in a month!
