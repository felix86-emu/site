---
layout: page
title: Contributing
permalink: /contrib/
---

Contributions are much needed! Emulators are big projects and there's always a lot of work to do!

# I want to optimize instructions
You can get an idea of what sort of RISC-V instructions we emit for an x86-64 instruction by looking in `counts/`. If some instruction looks like it could be implemented in a more efficient way, feel free to optimize its respective handler in `handlers.cpp` or `handlers_x87.cpp`.

If an instruction could be optimized when no flags need to be emitted or under specific circumstances, that's also welcome!

# I want to debug a game
There's some things to make your life easier.
Currently due to [a gdb bug](https://sourceware.org/bugzilla/show_bug.cgi?id=32248) our JIT reader gdb implementation is not ready.

Still, here's some tips:
- When in JIT code, the `s11` RISC-V register holds the x86-64 state
  - You can view the value individual registers like so: `p/x ((ThreadState*)$s11)->gprs[0]` or `p/x ((ThreadState*)$s11)->xmm[0]`
  - You can view the RIP value: `info reg $gp` in JIT code, `p/x ThreadState::Get()->rip` outside of JIT code
- Need to know at what offset and which library an address corresponds to? Use print_address from gdb, example: `call print_address(0x10050c)`
- The `FELIX86_CALLTRACE=1` environment variable is very useful when debugging. You can execute `call dump_states()` from gdb to print the calltraces. It should have symbols if it can find them and should tell you what binary the code is in
- If you are not in JIT code, you can get the `ThreadState` object using `p/x ThreadState::Get()`
- The `FELIX86_STRACE=1` environment variable makes the emulator produce a trace of all emulated syscalls it runs
- Logs are saved in `/tmp/felix86-<PID>-XXXXXX.log` for every run
- Verbose logging can be helpful sometimes, set `FELIX86_VERBOSE=1`
- The `FELIX86_SLEEP_ERROR` environment variable or the `sleep_on_error` option in `config.toml` can make it so a crashing program sleeps for 40 seconds after printing its PID, giving enough time to attach a debugger. This is particularily useful in situations with many `fork` and `execve` instructions, where debugging with gdb attached from the start can get messy

Feel free to report any findings in the compatibility list!

# I want to profile
There's symbol support for `perf`!

Three different modes exist:
- Name each block -- enable via `FELIX86_PERF_BLOCKS`
  - Can be used to identify hot blocks
  - You can also use `FELIX86_PERF_SYMBOLS` in combination with `FELIX86_PERF_BLOCKS` to export symbols for each block if available
- Name the entire code cache -- enable via `FELIX86_PERF_GLOBAL`
  - Can be used to identify if the hotspot is in the code cache or in C++ code
- Name each library -- enable via `FELIX86_PERF_LIBS`
  - Can be used to identify hot libraries

I use `perf top -e cpu-clock -d5 -p <PID>` to get a constantly refreshing view of hotspots.

# I want to report an issue with a game
Check out [https://github.com/felix86-emu/compatibility-list](https://github.com/felix86-emu/compatibility-list). Try to follow the format of other issues and use the template!

[https://felix86.com/compat/](https://felix86.com/compat/) is manually updated when new issues are added.
