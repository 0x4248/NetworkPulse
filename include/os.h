/**
 * Network Pulse
 * A simple arp table like tool to see if clients are connected and alive on the network.
 * GitHub: https://www.github.com/0x4248/NetworkPulse
 * Licence: GNU General Public License v3.0
 * By: 0x4248
 * 
 * OS header file
*/

#ifdef __linux__
#define OS "Linux"
#elif __APPLE__
#define OS "MacOS"
#elif __unix__
#define OS "Unix"
#endif