/**
 * Network Pulse
 * A simple arp table like tool to see if clients are connected and alive on the network.
 * GitHub: https://www.github.com/lewisevans2007/NetworkPulse
 * Licence: GNU General Public License v3.0
 * By: Lewis Evans
 * 
 * Pulse table header
*/

#include <string>
#include <vector>

void init_table();

void update_table(std::vector<std::string> ip_addresses, std::vector<std::string> hostnames, std::vector<std::string> operating_systems, std::vector<std::string> times_sent);