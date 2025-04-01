---
layout: post
title: April 2025 update
---

felix86 is a new x86-64 userspace emulator for RISC-V. It is aimed at achieving good performance in games, and as of now is in relatively early development. [A few games](https://felix86.com/compat/) are already fully working. As this is the first post, we are going to go through a brief introduction

## Inner workings

felix86 emulates an x86-64 CPU running in userspace, which is to say it is not a virtual machine like VMware, rather it directly translates the instructions of an application and uses the host Linux kernel to handle syscalls.

Currently, translation happens during execution time, also known as just-in-time (JIT) recompilation. The JIT recompiler in felix86 is focused on fast compilation speed and performs minimal optimizations. It utilizes extensions found on the host system such as the vector extension for SIMD operations, or the `B` extension for emulating bit manipulation extensions like BMI. The only mandatory extensions for felix86 are `G`,  which every RISC-V general purpose computer should already have, and v1.0 of the standard vector extension.

### Flags

The RISC-V architecture, unlike x86-64, has no flags -- thus flag calculations must be performed for some x86 instructions like `add`. In most cases flags go unused, so felix86 will not emit unnecessary flag calculations. This is performed by doing a forward scan of the instruction sequence it is about to compile (the basic block) and finding at which points flags are needed and at which points they are defined, effectively finding liveness ranges for each flag. Instructions that would emit flags check if the flags are actually used before doing so.

### Registers

RISC-V has 31 general purpose registers, 32 floating-point registers and 32 vector registers in the `V` extension. On the other hand, x86-64 has 16 GPRs and 16 XMMs, at least until AVX-512 and APX. Because of this, we can allocate 16 out of the 31 RISC-V GPRs for the 16 x86-64 GPRs, and 4 more for flag calculations, for the most important flags: `OF` `CF` `SF` and `ZF`. That leaves us with 11 registers for other uses. One of them is used for storing a pointer to the x86-64 state which we need to frequently access, and we also don't touch the `sp`, `gp` and `tp` registers as they serve a special purpose in the calling convention. That leaves us with 7 GPRs for scratch usage, which we allocate as we emit code, there's no linear scan or graph coloring for these for the sake of simplicity. One day there may be!

### Single instruction multiple data

The vector extension in RISC-V has been thus far very adequate in emulating x86-64 SSE instructions, and I think that will continue to be the case when we get to AVX. Only few instructions have caused difficulties in their emulation, namely the `pcmpxstrx` group of instructions which are currently emulated with a C function rather than recompiled code. However, most instructions have caused no problems and have a relatively smooth translation.

You can use the dropdown below to get an idea of some SIMD translations. Some are rougher than others, while some translate to a single instruction if you exclude `vsetivli`.

<html lang="en">
<head>
    <style>
        body {
            font-family: monospace;
            margin: 20px;
        }
        pre {
            background: #f4f4f4;
            padding: 10px;
            border-radius: 5px;
            white-space: pre-wrap;
        }
        .keyword { color: blue; font-weight: bold; }
        .register { color: green; }
        .immediate { color: red; }
    </style>
</head>
<body>
    <label for="instruction">Select an instruction:</label>
    <select id="instruction">
    </select>
    
    <h2>felix86's RISC-V translation:</h2>
    <pre id="codeBox">Select an instruction to view its equivalent code.</pre>
    
    <script>
        document.addEventListener("DOMContentLoaded", function() {
            const jsonData = {
                "0fc6d200": {
                    "instruction_count": 10,
                    "expected_asm": [
                        "VSETIVLI        zero, 1, e64, m1, tu, mu",
                        "ADDIW           ra, zero, 0",
                        "VMV.S.X         v22, ra",
                        "VMV.V.I         v0, 0b11",
                        "VMV.V.I         v23, 0",
                        "VSETIVLI        zero, 4, e32, m1, tu, mu",
                        "VRGATHEREI16.VV v23, v3, v22, v0",
                        "VMV.V.I         v0, 0b1100",
                        "VRGATHEREI16.VV v23, v3, v22, v0",
                        "VMV.V.V         v3, v23"
                    ],
                    "disassembly": "shufps xmm2, xmm2, 0x00"
                },
                "f30f58dc": {
                    "instruction_count": 2,
                    "expected_asm": [
                        "VSETIVLI        zero, 1, e32, m1, tu, mu",
                        "VFADD.VV        v4, v4, v5"
                    ],
                    "disassembly": "addss xmm3, xmm4"
                },
                "0f52dc": {
                    "instruction_count": 5,
                    "expected_asm": [
                        "VSETIVLI        zero, 4, e32, m1, tu, mu",
                        "LUI             ra, 0x3f800000(1.0)",
                        "VMV.V.X         v23, ra",
                        "VFSQRT.V        v22, v5",
                        "VFDIV.VV        v4, v23, v22"
                    ],
                    "disassembly": "rsqrtps xmm3, xmm4"
                },
                "660fe4d2": {
                    "instruction_count": 2,
                    "expected_asm": [
                        "VSETIVLI        zero, 8, e16, m1, tu, mu",
                        "VMULHU.VV       v3, v3, v3"
                    ],
                    "disassembly": "pmulhuw xmm2, xmm2"
                },
                "660ff60f": {
                    "instruction_count": 14,
                    "expected_asm": [
                        "VSETIVLI        zero, 16, e8, m1, tu, mu",
                        "VLE8.V          v29, a0, 1",
                        "VMV.V.I         v26, 0",
                        "VMV.V.I         v27, 0",
                        "VMIN.VV         v22, v2, v29",
                        "VMAX.VV         v23, v2, v29",
                        "VSUB.VV         v24, v23, v22",
                        "VSLIDEDOWN.VI   v25, v24, 8",
                        "VSETIVLI        zero, 8, e8, mf2, tu, mu",
                        "VWREDSUMU.VS    v26, v24, v26",
                        "VWREDSUMU.VS    v27, v25, v27",
                        "VSETIVLI        zero, 2, e64, m1, tu, mu",
                        "VSLIDE1UP.VX    v28, v27, zero",
                        "VOR.VV          v2, v28, v26"
                    ],
                    "disassembly": "psadbw xmm1, [rdi]"
                }
            };

            const riscVKeywords = ["VSETIVLI", "VFADD.VV", "LUI", "VMV.V.X", "VFSQRT.V", "VFDIV.VV", "VMULHU.VV", "VLE8.V", "VMV.V.I", "VMIN.VV", "VMAX.VV", "VSUB.VV", "VSLIDEDOWN.VI", "VWREDSUMU.VS", "VSLIDE1UP.VX", "VOR.VV", "ADDIW", "VMV.S.X", "VRGATHEREI16.VV", "VMV.V.V"];

            function highlightCode(code) {
                const keywordRegex = new RegExp(`\\b(${riscVKeywords.join('|')})\\b`, 'g');
                return code
                    .replace(keywordRegex, '<span class="keyword">$1</span>')
                    .replace(/\b(v\d+|zero|ra|a0)\b/g, '<span class="register">$1</span>')
                    .replace(/\b(\d+|0x[0-9A-Fa-f]+|0b[01]+)\b/g, '<span class="immediate">$1</span>');
            }

            function updateCode() {
                const select = document.getElementById("instruction");
                const codeBox = document.getElementById("codeBox");
                const selectedKey = select.value;

                if (selectedKey && jsonData[selectedKey]) {
                    const highlightedCode = jsonData[selectedKey].expected_asm.map(line => highlightCode(line)).join("<br>");
                    codeBox.innerHTML = highlightedCode;
                } else {
                    codeBox.innerHTML = "Select an instruction to view its equivalent code.";
                }
            }

            function populateDropdown() {
                const select = document.getElementById("instruction");
                select.innerHTML = "";
                for (let key in jsonData) {
                    let option = document.createElement("option");
                    option.value = key;
                    option.textContent = jsonData[key].disassembly;
                    select.appendChild(option);
                }
                select.addEventListener("change", updateCode);
                updateCode();
            }

            populateDropdown();
        });
    </script>
</body>
</html>

Some of these translations may be suboptimal! [Contributions are welcome](https://felix86.com/contrib/#i-want-to-optimize-instructions)! Alternatively, you can open an issue.

### x87

Currently x87 is probably the least optimized part of the translation. There's no register allocation and registers are loaded from memory and stored back at the end of each instruction. Luckily, most games rarely use x87 instructions. In the future, optimizations need to happen as older games use much more x87, especially ones compiled for x86.

### Other optimizations

felix86 also performs block linking, which is quite important for performance. Basic blocks that jump to a known target are patched to jump to that target directly (when it gets eventually compiled) instead of returning to the dispatcher.

There's also an option for return address prediction, to minimize jumps to the dispatcher even more. Basically in most cases each call will eventually correspond to a return which means we can predict the return address of each ret with pretty good accuracy. This involves pushing a predicted guest address and a host return address to the stack. If the prediction is right, we can use the host address directly, and if the prediction fails we can just jump to the dispatcher.

Currently I am working on thunking, using host libraries in place of guest ones for speed and compatibility, for example if a chip has a GPU with RISC-V drivers but no x86-64 drivers, thunking can enable usage of those RISC-V drivers and utilization of the GPU.

---

Thanks for reading the April post! That's all for now! See you in a month or two.

Make sure to check out (and star) the repo: [https://github.com/OFFTKP/felix86](https://github.com/OFFTKP/felix86)