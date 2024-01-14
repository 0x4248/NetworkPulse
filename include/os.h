/**
 * Network Pulse
 * A simple arp table like tool to see if clients are connected and alive on the network.
 * GitHub: https://www.github.com/lewisevans2007/NetworkPulse
 * Licence: GNU General Public License v3.0
 * By: Lewis Evans
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