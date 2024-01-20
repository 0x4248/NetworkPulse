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

CC = g++
CFLAGS = -Wall -std=c++11 -g

BIN = bin

all: init build-client build-server

build-server:
	@echo "[MAKE] Building server"
	@$(CC) $(CFLAGS) $(S-SOURCES) -I include -o $(BIN)/server
	@echo "[MAKE] Done building server"

build-client:
	@echo "[MAKE] Building client"
	@$(CC) $(CFLAGS) $(C-SOURCES) -I include -o $(BIN)/client
	@echo "[MAKE] Done building client"

init:
	@echo "[MAKE] Creating bin directory"
	@mkdir -p $(BIN)

help:
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

clean:
	@echo "[MAKE] Cleaning up"
	@rm -rf $(BIN)
	@echo "[MAKE] Done cleaning up"

client-files:
	@echo $(C-SOURCES)

server-files:
	@echo $(S-SOURCES)

menuconfig:
	@echo "[MAKE] Running menuconfig"
	@menuconfig
	@echo "[MAKE] Done running menuconfig"
	@genconfig
	@echo "[MAKE] Done generating config"
	@mv config.h include/config.h
	@echo "[MAKE] Done moving config"