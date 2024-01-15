# Network Pulse

A simple arp table like tool to see if clients are connected and alive on the network.

## Installation

Build the server and client using cmake and then install the binaries.

```bash
mkdir build
cd build
cmake ..
make
```

or you can use the makefile

```bash
make
```

This should create the binaries `server` and `client`. On the clients make sure the clients are running in the background.

## Configuration

Clients can be configured to talk to a specific server or port. The default is `192.168.1.1:2002`

The port can be changed via the command line argument `-p`. The server can be changed via the command line argument `-s`.

## Licence

This project is licenced under the GNU General Public Licence v3.0 - see [LICENCE](LICENCE) for details.