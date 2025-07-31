---
layout: post
title: felix86 25.08
---

A major milestone for felix86 was reached this month!

# Browsers

We were able to run the Chromium browser under felix86!

You may be wondering: why would anyone want to do that?

<img src="{{ site.baseurl }}/images/steam.png" width="800" style="display: block; margin: 10px auto"/>
_The Linux version of Steam, running on RISC-V with felix86_

A lot of modern apps use some kind of embedded version of Chromium. This ranges from the Windows Start Menu to Discord to Steam.

But Steam was always a huge goal for felix86. It has become the de facto launcher for games. Being able to launch games that use Steam DRM is great and allows us to test a wide variety of titles.

Steam itself is a 32-bit app. It uses a separate 64-bit tool called the `steamwebhelper` to render the GUI using the Chromium Embedded Framework. It also uses a tool called `pressure-vessel` for containerization. It does some tricky stuff with mounts and `pivot_root`.

If you'd like to try Steam, check out the [Steam setup guide](https://github.com/OFFTKP/felix86/blob/master/docs/steam.md).


#### Installation guide

There's also a quick installation guide for felix86 and Steam:

<div class="video-container">
    <iframe src="http://www.youtube.com/embed/SDTbd76VWws" height="315" width="560" allowfullscreen="" frameborder="0">
    </iframe>
</div>

## Optimizations

Most of the work this month was on getting Steam to work. However, we also optimized a few instructions.

One of the more interesting optimizations we made was the fusing of `cmp` instructions.

On RISC-V, if you want to check if, for example, register A is less than register B, you use the `slt` instruction.

On x86, you use the `cmp` instruction. The `cmp` instruction does a generic comparison between two registers and sets the flags accordingly. If you wanted to then set a register if A is *less than* B, you'd use the `setl` instruction after the `cmp`. The real operation of the `setl` instruction is checking if the overflow flag is not equal with the negative flag.

RISC-V doesn't have flags, so felix86 computes them in software. This is expensive, particularly for the overflow flag, which takes numerous instructions to calculate. Luckily, `cmp` has no side-effects other than flags. If we know that the flags are only used for the `setl` and then overwritten, we could emit the `cmp` and `setl` combo as a single `slt` RISC-V instruction. This is currently the only case where we can emit RISC-V assembly that is **shorter in instruction count than the original x86 code!**

This is currently only done for `cmp` and `cmovcc`, but in the future we will expand it to work with `setcc`. The most used combo would probably be `cmp` and `jcc`, but supporting this would require analyzing more than one block at once, which we currently don't do.

It should be noted that this optimization only works if the `cmp` is immediately followed by the instruction that uses the resulting flags. This is usually the case, but it's possible for a compiler to emit instructions that don't modify the flags between the two instructions. If deemed necessary, we could fuse `cmp` instructions even if the instruction that uses the flags is further down the line.

{% include note.html content="Theoretically, a program can rely on correct flag emulation even for unused flags by using signals. This would make the aforementioned optimization much trickier to do. In practice, signal handlers rarely rely on correct register state other than the current RIP (although felix86 will try to reconstruct the state at the time of the signal), and I've never seen them rely on correct flags. A well-crafted piece of DRM software could detect emulation when this optimization is enabled. If you are a DRM author consider forgetting about this." %}

This optimization is currently disabled by default as it needs more testing. To enable it, run `export FELIX86_FUSE_OPCODES=1`.

---

Thanks for reading this post.

If you like this project, please give us a star on Github: [https://github.com/OFFTKP/felix86](https://github.com/OFFTKP/felix86)