---
layout: post
title: felix86 25.09
---

Welcome to the monthly felix86 blog post. Summer slowed us down a bit, but we are preparing some big changes for next month.

## Optimizations

We managed to squeeze in a few optimizations. We now automatically compress RISC-V instructions whenever possible, using a new feature implemented in [Biscuit](https://github.com/lioncash/biscuit). Additionally, we optimized the implementation of some x86 instructions.

## New playable games

After some bug fixes in the latest version, the compatibility list has been updated with new working titles, notably Sleeping Dogs and Counter-Strike: Source.

## What we are working on

### 32-bit signal support

Some 32-bit games require signals to function. This is usually the case with Windows games run through `wine`.
Currently, felix86 only supports signals for 64-bit applications, but we are working on supporting 32-bit signals.
This may allow several 32-bit Windows games to run.

Not all Windows games require signals. Signals are primarily used in Wine for emulating the [Asynchronous Procedure Call](https://learn.microsoft.com/en-us/windows/win32/sync/asynchronous-procedure-calls) mechanism. Some 32-bit Windows games operate fine without signal support, such as Fallout 2 or Trackmania Nations Forever.

### Reducing vector pipeline stalls

After a chat with the folks at [FEX-Emu](https://github.com/FEX-Emu/FEX), it came to our attention that instructions that change the vector configuration may be a decent overhead in current hardware.

While modern hardware may utilize register renaming to avoid a pipeline stall whenever the configuration is changed, current RISC-V hardware likely lacks this optimization.

It is the case that felix86 avoids emitting `vsetivli` instructions whenever the configuration wouldn't be changed at a basic block level. However, we have something in most SSE instruction handlers that would emit an additional `vsetivli` whenever the instruction has a memory operand. It was falsely assumed that all SSE instructions can do unaligned memory access (this is not true, it's something that only exists in AVX land) so when loading the memory operands we would set the vector configuration to sixteen 8-bit elements, allowing for unaligned access. Since this is not necessary, it can reduce `vsetivli` instructions when a memory operand is involved, potentially improving performance. We should also look into instruction handlers that use more vector configuration changes than necessary!

---

Thanks for reading the August post.

If you like this project, please give us a star on Github: [https://github.com/OFFTKP/felix86](https://github.com/OFFTKP/felix86)