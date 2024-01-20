/**
 * Network Pulse
 * A simple arp table like tool to see if clients are connected and alive on the network.
 * GitHub: https://www.github.com/lewisevans2007/NetworkPulse
 * Licence: GNU General Public License v3.0
 * By: Lewis Evans
 * 
 * Logging source file
*/

#include <string>
#include <iostream>

#include "config.h"

#ifdef CONFIG_SHOW_PULSES
void pulse_log(std::string message){
    std::cout << "\033[1;34m[ PULSE ]\t\033[0m " << message << std::endl;
}
#else
void pulse_log(std::string message){
    return;
}
#endif

#ifdef CONFIG_ENABLE_LOGGING 
void log(std::string type, std::string message){
    if (type == "REGISTER"){
        std::cout << "\033[1;32m[ REGISTER ]\t\033[0m " << message << std::endl;
    } else if (type == "PULSE"){
        pulse_log(message);
    } else if (type == "LOST"){
        std::cout << "\033[1;31m[ LOST ]\t\033[0m " << message << std::endl;
    } else if (type == "DEBUG"){
        std::cout << "\033[1;37m[ DEBUG ]\t\033[0m " << message << std::endl;
    } else if (type == "ERROR"){
        std::cout << "\033[1;31m[ ERROR ]\t\033[0m " << message << std::endl;
    } else {
        std::cout << "\033[1;37m[ DEBUG ]\t\033[0m " << message << std::endl;
    }
}
#else
void log(std::string type, std::string message){
    return;
}
#endif