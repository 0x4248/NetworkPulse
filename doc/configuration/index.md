# Configuration

Network pulse uses the Kconfig system. This allows you to configure the entire project from a single menu.

## Config prerequisites

- Build-essential
- Make
- Python
- KconfigLib

You can install these on Ubuntu with the following command:

```bash
sudo apt install build-essential make python3
python3 -m pip install kconfiglib
```

## Configuration

To configure run `make menuconfig` this will bring up a menu where you can edit the configuration. This will create a `.config` and then also generate a `config.h` file. The makefile will then move the `config.h` file to the `include` directory where it will be included in the build.

You can manually do this by doing `genconfig` and then `mv config.h include/config.h`.