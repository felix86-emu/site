---
layout: post
title: May 2025 update
---

A lot of progress was made during the month of April!

Before we get into it, I would like to thank our donors on Ko-Fi who have helped me gather funds for hardware!

In particular, I'd like to thank [Sonicadvance1](https://github.com/Sonicadvance1) from [FEX-Emu](https://github.com/FEX-Emu/FEX)<a href="https://github.com/FEX-Emu/FEX"><img class="inline-icon" src="https://avatars.githubusercontent.com/u/61863475"></a> for his significant $1000 donation. This has helped me acquire a lot of new hardware and have money left for future RISC-V boards and GPUs. Thanks a lot!

You can learn more [at the project's Ko-fi page](https://ko-fi.com/felix86)!

# The GPU trials
Using a proper GPU with a RISC-V board is... tricky currently.

Initially I tried an NVIDIA GTX 1050 Ti, but I quickly realized the Bianbu OS has no `nouveau` driver support, and obviously there's no NVIDIA proprietary drivers for RISC-V. Next, the AMD Radeon HD 7790 was tried, [however that brought up errors](https://forum.banana-pi.org/t/amd-hd-7790-gpu-initialization-failed/22846) during initialization. Finally, the AMD HD 7350 was purchased as the Bianbu wiki claims it is supported, and it turned out to be true.

<img src="{{ site.baseurl }}/images/hd7350.jpg" width="300" style="display: block; margin: 10px auto"/>
_The BPI-F3 has no PCIe slot, the mPCIe has to be used with an adapter_

Being able to use a GPU has been very helpful. All games prior to this point were running with llvmpipe, which is a software GPU fallback that draws graphics using your CPU. This is extremely expensive, and exponentially so for any game that does anything other than copy a framebuffer to the screen. Some games managed to cope, like VVVVVV at "decent" framerates, while others like World of Goo would run at a staggering 0.5 frames per second. Other games like SuperTuxKart would freeze during the compilation of certain shaders, which would happen both on actual x86-64 hardware and under felix86. Having a GPU present allowed SuperTuxKart to get us into a race at an acceptable 20 frames per second, which we hope to raise in the future!

<img src="{{ site.baseurl }}/images/stk.jpg" width="700" style="display: block; margin: 10px auto"/>
_We can finally race!_

Getting a GPU to work provided a great performance boost in most games. Some games, though, were very stubborn to continue running slowly. In the next section you'll find out why!

# Notable changes

## Self-modifying code

During April, initial support for self-modifying code was added.

Self-modifying code is code that modifies itself. This can take many forms:
- A library being loaded at an address, unloaded, and a different library being loaded at the same address
- A recompiler making modifications to its own code for performance, such as block linking
- Anti-emulator tactics such as modifying the next instruction, this can trip up recompilers

The reason self-modifying code is a problem is because recompilers compile chunks of code at a time (called basic blocks) and cache them to prevent future recompilations. This caching happens based on the address. If there's self-modifying code however, the underlying guest code has changed but the cached host code is still the same. In those scenarios, we need to mark those blocks as invalid and recompile them. This is the basic idea, there's other techniques that deal with other types of self-modifying code for better performance.

Without self-modifying code support, **Celeste** would run, but *very very slowly*. The loading times were the worst part, the game took around 100 seconds just to load the graphics, getting to the menu could take up to 10 minutes or more. The menu would render at less than 2 FPS, **with or without a GPU**.

With self-modifying code support, these loading times were vastly reduced and the game could run at around **25 FPS** with some stutter when loading new areas. This is a massive boost in performance and was quite unprecedented!

The reason here is that Celeste is a game written in C#. This game runs under a C# runtime environment with a JIT that translates [CIL](https://en.wikipedia.org/wiki/Common_Intermediate_Language) to host machine code. This environment, called Mono, has a lot of self-modifying code where the originally slow recompiled code gets gradually optimized to perform faster. Now, if there's no self-modifying code support, these optimizations never get realized by our emulator, as it will continue running the old cached code and not notice the guest code has been modified, thus performing a lot worse.

Not all types of self-modifying code are supported yet, but library loading/unloading (via the use of munmap and mmap) is supported, and the same goes for self-modifying code on blocks other than the currently executing one. There's a nasty possible case of self-modifying code where instructions within the block itself are modified, but this is maliciously done by anti-cheat or DRM software, and we are not at that point yet.

---

Detecting self-modifying code happens by disallowing write access to pages that contain guest code that we recompiled. A signal handler will then be triggered on writes to these pages and we can invalidate the blocks in those pages by using a map to find all blocks contained within them for all the threads.

<img src="{{ site.baseurl }}/images/celeste.png" width="700" style="display: block; margin: 10px auto"/>
_After fixing a couple more bugs, Celeste now gets in game, and at ~25 FPS!_

## 8-bit and 16-bit atomic implementations

While RISC-V has atomic operations like `amoadd`, `amoxor`, `amoswap` (and more) to match x86-64's `lock add`, `lock xor`, `lock xchg` (and others) by default it only supports 32-bit and 64-bit operations. An extension named `Zabha` adds 8-bit and 16-bit support, however no RISC-V hardware implements it right now. To emulate 8-bit and 16-bit atomics we need to use `lr.w` and `sc.w` and do some shifting and masking to perform the operation on an 8-bit or 16-bit value within the 32-bit word.

8-bit and 16-bit `lock xchg` support was added, as some games were using it, and not atomically emulating this instruction can cause random deadlocks or data races.

## Wine

Emulating the `wine` compatibility layer has caused us problems in the past, but after many bug fixes it has successfully run its first program, a simple `hello_world.exe` file.

For example, one of the problems were that we were using the host `epoll_event` struct to emulate the `epoll` syscalls like `epoll_ctl` or `epoll_pwait`. This is wrong however, as the `epoll_event` struct is packed in x86-64 but not packed in RISC-V for backwards compatibility reasons. This would cause issues with the wineserver communication and the application would get stuck.

I also believe marking blocks as invalidated during mmaps played some role in getting it to work.

---

Additionally, I can now run a few simple Windows games through wine, which is quite the progress since last month:
<img src="{{ site.baseurl }}/images/solitaire.png" width="600" style="display: block; margin: 10px auto"/>
_Windows 7 Solitaire now runs under felix86_

## Better user experience

A few things have been added that will enhance user experience and get us closer to a proper release

### apt support

The necessary syscalls for the `apt` command have been implemented. This means that the guest `apt` command can be used to directly install files in the rootfs if your OS is Debian. This can be very helpful when installing packages that have multiple libraries, binaries, data and configuration files. In the past we had to move everything with `scp` which was especially tiresome when installing certain libraries.

That being said, it may be preferrable to use the host `apt` command to install x86-64 executables on a specific path.
For example, `sudo apt -o Dir=/rootfs -o Architecture=amd64 install myPackage` seems to be able to achieve such a thing. In some cases both the host and guest version may need to be installed, for example if an application needs to interact with a systemd service.

### Config files

The emulator now has two ways of configuration:
- Using the `/home/$USER/.config/felix86/config.toml` file that will be created after the first run
- Using environment variables

Environment variables allow for quicker short-term configuration while editing the config file allows for long-term configurations without polluting your global environment variables. You can print all the configurations by running `felix86 --configs` or by reading the `config.inc` file in the source code.

### binfmt_misc support

`binfmt_misc` is a neat utility in the Linux kernel that allows executing file formats that wouldn't be recognized otherwise. In our case, we want to detect x86 and x86-64 applications and try to run them under felix86.  Registering an emulator for this purpose is [quite easy](https://www.kernel.org/doc/html/latest/admin-guide/binfmt-misc.html). This means that, as long as the rootfs path is set and the emulator is installed, x86-64 and x86 executables can be executed without prepending the emulator path and the kernel will pass them to our emulator.

To register the emulator in binfmt_misc, use `sudo felix86 -b`. You can use the same command to unregister the emulator.

### Kill all instances

Some applications, like `wine`, spawn a bunch of daemons that stick around even after the original application has been killed. A new argument is available in felix86, the `-k` or `--kill-all` which kills all active instances of felix86.

## Moving towards 32-bit program support

With the latest changes, some 32-bit applications are showing signs of life! There's no working 32-bit games at the moment, but we are inching closer.

### New instructions
As we are moving towards supporting 32-bit programs, some previously irrelevant instructions become relevant again.

For example, the `cmpxchg8b` instruction, which was used in the pre-x86_64 era to perform a 64-bit atomic compare exchange, is needed for some 32-bit programs. Thankfully, this can be implemented with `LR.D`/`SC.D`, which is unlike the `cmpxchg16b` which is currently impossible to implement in an atomic way apart from using a global lock on every read or write, which would completely shred performance. The `Zacas` extension is going to make proper `cmpxchg16b` implementation possible, but it's not in the RVA23 profile so it may take a while. Regardless, if felix86 can find the `Zacas` extension, it will make use of it.

### New 32-bit syscalls
Along with instructions, new syscalls need to be supported for 32-bit programs. Unlike 64-bit programs, the syscalls here are more tricky to implement. Since pointers are 32 bits, there's a mismatch with structs used in many host syscalls and marshalling needs to occur. For some syscalls like `sendmsg` this is trickier, as multiple structs need to be marshalled and lengths adjusted. There's many syscalls that don't occur in 64-bit mode and need to be emulated with more modern versions.

### MMX support
The MMX instructions are largely unused in modern programs because you have SSE instructions that can do the same things on larger registers. Still, modern programs sometimes use them.

For example, some versions of SDL2 have paths that have MMX support and integer support, but no SSE support, so at runtime the MMX path would be preferred. Since I procrastinated on implementing MMX, I disabled the feature in the emulated CPUID, only keeping it enabled during the initial `ld.so` checks, which assert that the ISA level is adequate to run the application.

There's now MMX support, and 8 of the 15 remaining vector registers were statically allocated for the MM0-MM7 registers. In case you thought MMX registers are the 64-bit part of XMM registers (like I thought before starting this emulator), no, they are actually part of the ST0-ST7 x87 registers.

Because MMX and x87 FPU instructions operate on the same registers, the `emms` instruction is used before running any x87 instructions and after running any MMX instructions. This is great, because we have an easy switch point to flush our allocated MMX registers.

Most MMX instructions are implemented using the already existing SSE handlers, while some like `punpckh` have differences due to the smaller register size, so they were handled a little more specially.

---

That was it for the May post! See you in a month!

Make sure to check out (and star) the repo: [https://github.com/OFFTKP/felix86](https://github.com/OFFTKP/felix86)
