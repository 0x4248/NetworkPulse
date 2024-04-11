/**
 * Network Pulse
 * A simple arp table like tool to see if clients are connected and alive on the network.
 * GitHub: https://www.github.com/0x4248/NetworkPulse
 * Licence: GNU General Public License v3.0
 * By: 0x4248
 * 
 * Pulse table source
*/

#include <string>
#include <vector>
#include <fstream>

#include "table.h"
#include "config.h"


#ifndef CONFIG_PULSE_TABLE_FILE_NAME
#define CONFIG_PULSE_TABLE_FILE_NAME "pulse_table"
#endif


#ifdef CONFIG_PULSE_TABLE
void init_table(){
    std::string file_name = CONFIG_PULSE_TABLE_FILE_NAME;
    std::ifstream file(file_name);
    if (file.good()){
        std::remove(file_name.c_str());
    }
    std::ofstream pulse_table(file_name);
    pulse_table << "PulseTable (Awaiting connection)" << std::endl;
}

void update_table(std::vector<std::string> ip_addresses, std::vector<std::string> hostnames, std::vector<std::string> operating_systems, std::vector<std::string> times_sent){
    std::string file_name = CONFIG_PULSE_TABLE_FILE_NAME;
    std::ofstream pulse_table(file_name);
    if (ip_addresses.size() != 0) {
        for (int i = 0; i < ip_addresses.size(); i++){
            pulse_table << ip_addresses[i] << "," << hostnames[i] << "," << operating_systems[i] << "," << times_sent[i] << std::endl;
        }
    } else {
        pulse_table << "PulseTable (Awaiting connection)" << std::endl;
    }
}
#else
void init_table(){}
void update_table(std::vector<std::string> ip_addresses, std::vector<std::string> hostnames, std::vector<std::string> operating_systems, std::vector<std::string> times_sent){}
#endif