# STM32F411CEU6 BlackPill -- Blinky

A "blinky" project for the STM32F411CEU6 Black Pill development board. Mainly
understood as a starting point to my drone project.

Project structure
- `include/`: custom header files (`*.h`)
- `src/`: C source files (`*.c`)
    - expection: `src/bin/` -- build directory (`*.o`, `*.d*`, `*.elf`, `*.bin`)
- `lib/`: third-party libraries
    - `lib/libopencm3/`: the
      [libopencm3](https://github.com/libopencm3/libopencm3) library; a [Git
      submodule](https://git-scm.com/book/en/v2/Git-Tools-Submodules)

Note: this is an adjusted version of the [libopencm3
template](https://github.com/libopencm3/libopencm3-template).

## Instructions

Clone the repo
```bash
cd /path/to/your/project
git clone --recurse-submodules <url_of_this_repo.git>
```

Build the libopencm3 library (only needed once)
```bash
make -C lib/libopencm3
```

Build the project
```bash
make
```

Verify that there's a `src/bin/blinky.elf` and `src/bin/blinky.bin`. You can
disassemble the `blinky.elf` with
```bash
arm-none-eabi-objdump -D src/bin/blinky.elf
```

Flash the `blinky.bin` onto the MCU
```bash
make flash
```

The LED on board of the Black Pill should blink now.

You can clean the files introduced by building the project with
```bash
make clean
```

You can start a debugging server on localhost and some port (see output) with
```bash
make debug
```

Install `gdb-multiarch` (**TODO**: or `arm-none-eabi-gdb`)
```bash
sudo apt install gdb-multiarch
```

Connect GDB to the debugging server as follows (assuming port is `4242`)
```bash
gdb-multiarch src/bin/blinky.elf
(gdb) target extended-remote localhost:4242
```
