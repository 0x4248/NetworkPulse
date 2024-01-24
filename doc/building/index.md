# Building

There are several ways to build network pulse. The easiest is to use cmake.

## Prerequisites

- CMake
- KconfigLib
- Build-essential
- Make
- Python

You can install these on Ubuntu with the following command:

```bash
sudo apt install cmake build-essential make python3
python3 -m pip install kconfiglib
```

## Configuration

Network pulse uses the Kconfig system. This is why `KconfigLib` is required. To configure run `make configure` this will bring up a menu where you can turn features on or off and configure the default ports.

## Building with CMake

To build with cmake, run the following command:

```bash
sh tools/build_cmake.sh
```

## Building with Make

To build with make, run the following command:

```bash
make
```
