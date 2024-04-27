# Network Pulse
# A simple arp table like tool to see if clients are connected and alive on the network.
# GitHub: https://www.github.com/0x4248/NetworkPulse
# Licence: GNU General Public License v3.0
# By: 0x4248
#
# CMake Build Instructions

cmake_minimum_required(VERSION 3.15)

project(NetworkPulse)

# Version
set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 0)

# C++ flags
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Debug flags
set(CLIENT_FILES src/client.cpp src/modules/hostname.cpp)
set(SERVER_FILES src/server.cpp src/modules/logger.cpp src/modules/table.cpp)

# Client executable
add_executable(client ${CLIENT_FILES})
# Server executable
add_executable(server ${SERVER_FILES})

include_directories(include)
