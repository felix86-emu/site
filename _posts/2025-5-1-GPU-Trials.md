---
layout: post
title: May 2025 update
---
Using a proper GPU in a RISC-V boards is... tricky currently.

A few things to note:
- PowerVR GPUs such as IMG BXE-2-32 in the BPI-F3 could be used via thunking, however their drivers are closed-source and buggy
  - vkcube/vulkainfo currently just segfaults. Games like supertuxkart can use Vulkan and look fine, but getting thunking
  to work when you aren't sure if your code is buggy or the driver is buggy is not ideal
  - GLX apps are not able to use the GPU on my machine and fall back to softpipe
  - EGL + OpenGL ES apps seem to work... usually -- but most games use either GLX or Vulkan
- BPI-F3 has an mPCIe port which can be used to plug in a GPU in theory... In practice however:
  - There's no nouveau driver support (and obviously no official RISC-V NVIDIA driver)
  - There's no amdgpu driver support
  - There's radeon driver support with some hacks in the linux 6.6 kernel, which is the latest
  - The AMD Radeon HD 7790 GPU I tried is detected, however [fails to initialize with ENOMEM](https://forum.banana-pi.org/t/amd-hd-7790-gpu-initialization-failed/22846)
  - [A page in the wiki](https://bianbu-linux.spacemit.com/en/graphics/AMD_graphics_card_adaptation_reference/) claims that an older GPU, the AMD Radeon HD 7350 works, I've ordered one to try it out
- The Milk-V Jupiter has been successfully tried with some AMD GPUs by some people, however:
  - I don't have a Milk-V Jupiter
  - Getting one may not be worth, as the CPU is the same and the only benefit is the PCIe slot
  - Shipping is expensive in Europe as they don't ship through Europe
- The Milk-V Pioneer actually comes equipped with an AMD GPU and is very powerful. However:
  - It is prohibitively expensive
  - It comes with RVV 0.7, unlike BPI-F3 or Milk-V Jupiter, which would need some work to support and is going to get phased out in future chips
