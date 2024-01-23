# Network Pulse
# A simple arp table like tool to see if clients are connected and alive on the network.
# GitHub: https://www.github.com/lewisevans2007/NetworkPulse
# Licence: GNU General Public License v3.0
# By: Lewis Evans
#
# Makefile
#
# Want to add a new source file? Add it to sources.mk

include sources.mk

VERSION = 6
PATCH = 6
SUBLEVEL = 2

CC = g++
CFLAGS = -Wall -std=c++11 -g

BIN = bin

all: init build-client build-server

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
	@genconfig
	@echo "CONF\tDone generating config"
	@mv config.h include/config.h
	@echo "CONF\tDone moving config"

defconfig:
	@echo "CP\tCopying default config"
	@cp tools/config/defconfig.conf .config
	@echo "CP\tDone copying default config"