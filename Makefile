# Network Pulse
# A simple arp table like tool to see if clients are connected and alive on the network.
# GitHub: https://www.github.com/0x4248/NetworkPulse
# Licence: GNU General Public License v3.0
# By: 0x4248
#
# Main makefile
#
# This makefile reads two files sources.mk and variables.mk, sources.mk contains 
# the sources for the server and the client. The variables.mk contains all the 
# variables for the compiler and all of its options. This makefile should only 
# contain rules and the version variables. 
#
# For a full list of rules and their description run make help.
#
# Is it recommended that you run make menuconfig to configure this project
# before modifying or installing on to a system. From menuconfig you will see
# two main menus one for the server and one for the client from there you can
# configure default ports, default IP addresses and logging settings. In order
# to run menuconfig you will need to have kconfiglib installed.
#
# You can install kconfiglib using the python package manager. Just run pip install
# kconfiglib. After that you can run make menuconfig. Once you exit menuconfig the
# makefile will run genconfig which will turn the .config file into a C header file
# stored in include/config.h. Changes to this file can be reverted by running make 
# defconfig and make restoreconfig.

include sources.mk
include variables.mk

# Version 
VERSION = 1
PATCH = 0
SUBLEVEL = 0

# Rules
all: init genversion build-client build-server

build-server:
	@echo "CC\tBuilding server"
	@$(CC) $(CFLAGS) $(S-SOURCES) -I include -o $(BIN)/server
	@echo "CC\tDone building server"

build-client:
	@echo "CC\tBuilding client"
	@$(CC) $(CFLAGS) $(C-SOURCES) -I include -o $(BIN)/client
	@echo "CC\tDone building client"

init:
	@echo "MKDIR\tCreating bin directory"
	@mkdir -p $(BIN)

help:
	@echo "Network Pulse Makefile (v$(VERSION).$(PATCH).$(SUBLEVEL))"
	@echo "Usage: make [target]"
	@echo "Targets:"
	@echo "  all: Builds both the client and the server"
	@echo "  build-client: Builds the client"
	@echo "  build-server: Builds the server"
	@echo "  init: Creates the bin directory"
	@echo "  help: Prints this help message"
	@echo "  clean: Cleans up the bin directory"
	@echo "  client-files: Prints the client source files"
	@echo "  server-files: Prints the server source files"
	@echo "  menuconfig: Runs menuconfig"
	@echo "  defconfig: Copies the default config"
	@echo "  backupconfig: Backs up the current config"
	@echo "  restoreconfig: Restores the backed up config"
	@echo "  genversion: Generates the version file"

clean:
	@echo "RM\tCleaning up"
	@rm -rf $(BIN)
	@echo "RM\tDone cleaning up"

client-files:
	@echo $(C-SOURCES)

server-files:
	@echo $(S-SOURCES)

menuconfig:
	@echo "CONF\tRunning menuconfig"
	@menuconfig
	@echo "CONF\tDone running menuconfig"
	@genconfigq
	@echo "CONF\tDone generating config"
	@mv config.h include/config.h
	@echo "CONF\tDone moving config"

defconfig:
	@echo "CP\tCopying default config"
	@cp tools/config/defconfig.conf .config
	@echo "CP\tDone copying default config"

backupconfig:
	@echo "CP\tBacking up config"
	@cp include/config.h tools/config/backup.h
	@echo "CP\tDone backing up config"

restoreconfig:
	@cp tools/config/backup.h include/config.h

genversion:
	@mkdir -p tools/version/build
	@$(C_CC) tools/version/set_version.c -o tools/version/build/set_version
	@tools/version/build/set_version
