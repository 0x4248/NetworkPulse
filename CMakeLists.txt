# Network Pulse
# A simple arp table like tool to see if clients are connected and alive on the network.
# GitHub: https://www.github.com/lewisevans2007/NetworkPulse
# Licence: GNU General Public License v3.0
# By: Lewis Evans
#
# CMake Build Instructions

cmake_minimum_required(VERSION 3.15)

project(NetworkPulse)

add_executable(client src/client.cpp)
add_executable(server src/server.cpp)

set_property(TARGET server client PROPERTY CXX_STANDARD 11)

include_directories(include)