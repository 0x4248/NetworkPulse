# Network Pulse
# A simple arp table like tool to see if clients are connected and alive on the network.
# GitHub: https://www.github.com/0x4248/NetworkPulse
# Licence: GNU General Public License v3.0
# By: 0x4248
#
# Makefile sources file.
#
# Important info about this file:
# This is used by the Makefile to know what files to compile.
# Becuse there are two different programs, the client and the server,
# its easier to list out what files compile to what program.
# This file is included in the Makefile, so the Makefile can use the variables
# defined here.

# CLIENT SOURCES
C-SOURCES += src/client.cpp
C-SOURCES += src/modules/hostname.cpp

# SERVER SOURCES
S-SOURCES += src/server.cpp
S-SOURCES += src/modules/logger.cpp
S-SOURCES += src/modules/table.cpp