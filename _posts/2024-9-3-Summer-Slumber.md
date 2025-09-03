---
layout: post
title: felix86 25.09
---

Welcome to the monthly felix86 blog post. Summer slowed us down a bit, but we are preparing some big changes for next month.

## 32-bit signal support

Some 32-bit games require signals to function. This is usually the case with Windows games run through `wine`.
Currently, felix86 only supports signals for 64-bit applications, but we are working on supporting 32-bit signals.
This may allow several 32-bit Windows games to run.

Not all Windows games require signals. Signals are primarily used in Wine for emulating the [Asynchronous Procedure Call](https://learn.microsoft.com/en-us/windows/win32/sync/asynchronous-procedure-calls) mechanism. Some 32-bit Windows games operate fine without signal support, such as Fallout 2 or Trackmania Nations Forever.

## Optimizations

We managed to squeeze in a few optimizations. We now automatically compress RISC-V instructions whenever possible, using a new feature implemented in [Biscuit](https://github.com/lioncash/biscuit). Additionally, we optimized the implementation of some x86 instructions.

## New playable games

After some bug fixes in the latest version, the compatibility list has been updated with new working titles, notably Sleeping Dogs and Counter-Strike: Source.

---

Thanks for reading the August post.

If you like this project, please give us a star on Github: [https://github.com/OFFTKP/felix86](https://github.com/OFFTKP/felix86)