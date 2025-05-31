---
layout: post
title: felix86 25.06
---

Welcome to another felix86 blog post. This month we got Unity and 32-bit games working and made many performance improvements!

## Easier installation
On Ubuntu/Debian/Bianbu and possibly other distros, you can now install felix86 and a rootfs with a single command:
```
curl -s https://raw.githubusercontent.com/OFFTKP/felix86/master/src/felix86/tools/install.sh -o /tmp/felix86_install.sh && bash /tmp/felix86_install.sh && rm /tmp/felix86_install.sh
```

So go ahead and try it out!

## Unity, UE3, and 32-bit games
There were many bug fixes during the month of May! One of the features we miss the most in RISC-V for x86-64 emulation is 128-bit compare exchange (CAS). This is necessary for proper emulation of the `cmpxchg16b` instruction. Unfortunately, no hardware currently supports the `Zacas` extension, which adds 128-bit CAS. The `cmpxchg16b` instruction is used extensively by Unity games, and improper emulation leads to frequent crashes and bugs.

Until we get `Zacas` in hardware, we have implemented a half-solution of using a global lock on every `cmpxchg16b` instruction. This makes it atomic with respect to other `cmpxchg16b` instructions, but not with other memory reads/writes. Turns out this is good enough to fix Unity games!

<img src="{{ site.baseurl }}/images/cuphead.png" width="800" style="display: block; margin: 10px auto"/>
_Cuphead, a Unity game, now playable on RISC-V with felix86_

Other bug fixes have made at least one Unreal Engine 3 game playable, and maybe more that I haven't tested.

<img src="{{ site.baseurl }}/images/outlast.webp" width="800" style="display: block; margin: 10px auto"/>
_Not many Unreal Engine 3 games for Linux out there_

Additionally, after even more bug fixes, 32-bit ioctl marshalling support for radeon, and new x87 instructions, some 32-bit games are playable!

<img src="{{ site.baseurl }}/images/portal2.png" width="800" style="display: block; margin: 10px auto"/>
_Now you're thinking with portals_

## Thunking GLX

OpenGL thunk libraries now work! Games can load an overlay `libGL.so`/`libGLX.so` which will make calls into host code.

If you installed felix86 using the script, you can enable thunking using `export FELIX86_ENABLED_THUNKS=glx`. It is currently disabled by default, as it needs more testing.

If you compiled felix86 make sure to set `FELIX86_THUNKS` to `/path/to/felix86/source/src/felix86/hle/guest_libs`.

### Technical ramble
One benefit of userspace emulators is they are allowed to employ some tricks for performance gains. For example, many libraries have a stable API across architectures. This means that if a program runs `glDrawArrays` for example, the host `glDrawArrays` *could* be used.

#### Quick brief on OpenGL inner workings
Things aren't so simple, however. OpenGL works with a global context. The functions are loaded from an implementation-defined function that returns function pointers. On Linux, this will be either `glXGetProcAddress` or `eglGetProcAddress`. This means that thunking OpenGL essentially means thunking GLX and/or EGL.

Thunking GLX brings other problems. GLX interacts with X11 -- it uses structs from X11 like the `Display` struct. The inner layout of this struct *is* architecture dependent. This not only means that you'd need to thunk `libX11`, but that it's also difficult to do so as some structs differ in their layout.

#### FEX to the rescue
Thankfully there's a way to get around needing to thunk `libX11`. You can create a host-side `Display` object and convert between the host and guest `Display` pointers when calling GLX functions that use `Display`. This idea is from [FEX-Emu](https://github.com/FEX-Emu/FEX/blob/main/ThunkLibs/include/common/X11Manager.h) and it saves us a lot of frustration.


## Thunking LuaJIT

Some games use Lua scripts. Other games like Balatro are entirely made in Lua. A popular speedy implementation of Lua is LuaJIT, which recompiles Lua code to machine code. However, LuaJIT does some things which invalidate our recompiled RISC-V code. This would previously cause significant slowdown in Balatro.

We now thunk the `libluajit.so` library, running the RISC-V LuaJIT in place of the x86-64 LuaJIT! This has caused significant performance improvements in Balatro and potentially other LÖVE engine games.

<img src="{{ site.baseurl }}/images/balatro.png" width="800" style="display: block; margin: 10px auto"/>
_Balatro went from 2 FPS to 30 FPS and 100% GPU usage, so a GPU upgrade could push it even further!_

LuaJIT can call C code from quite a few places, which means our host code needs to wrap the callbacks. You can see this happening in `thunks_luajit.cpp`. Whenever a C function is registered to be callable from Lua, we wrap it in code that will invoke the recompiler and fix up the arguments from the x86-64 ABI to the RISC-V ABI.

Enabling this needs you to compile [LuaJIT for RISC-V](https://github.com/plctlab/LuaJIT/commits/riscv64-v2.1-branch/), install it, and run `export FELIX86_ENABLED_THUNKS=lua`.

You can also thunk multiple libraries like we did for the Balatro image: `export FELIX86_ENABLED_THUNKS=glx,lua`

---

Thanks for reading the June post!

[Contributions are welcome!](https://felix86.com/contrib/) Anybody interested in RISC-V or x86 can help!

If you find this project interesting, please [star the repository](https://github.com/OFFTKP/felix86).
