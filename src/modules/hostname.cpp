/**
 * Network Pulse
 * A simple arp table like tool to see if clients are connected and alive on the network.
 * GitHub: https://www.github.com/lewisevans2007/NetworkPulse
 * Licence: GNU General Public License v3.0
 * By: Lewis Evans
 * 
 * Hostname module source file
*/

#include <string>
#include <unistd.h>

#include "hostname.h"

std::string get_hostname(){
    char hostname[1024];
    hostname[1023] = '\0';
    gethostname(hostname, 1023);
    return hostname;
}