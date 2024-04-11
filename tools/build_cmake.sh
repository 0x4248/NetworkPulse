# Network Pulse
# A simple arp table like tool to see if clients are connected and alive on the network.
# GitHub: https://www.github.com/0x4248/NetworkPulse
# Licence: GNU General Public License v3.0
# By: 0x4248
#
# CMake build script for Network Pulse

if ! command -v cmake &> /dev/null
then
    echo "CMake could not be found, please install it and try again."
    exit
fi

if ! command -v make &> /dev/null
then
    echo "Make could not be found, please install it and try again."
    exit
fi

if ! command -v g++ &> /dev/null
then
    echo "G++ could not be found, please install it and try again."
    exit
fi

mkdir -p build
cd build
cmake ..
make
cd ..

echo "Build complete"