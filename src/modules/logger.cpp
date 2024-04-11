/**
 * Network Pulse
 * A simple arp table like tool to see if clients are connected and alive on the network.
 * GitHub: https://www.github.com/0x4248/NetworkPulse
 * Licence: GNU General Public License v3.0
 * By: 0x4248
 * 
 * Logging source file
*/

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "config.h"

#ifndef CONFIG_PULSE_LOG_FILE_NAME
#define CONFIG_PULSE_LOG_FILE_NAME "pulse_log"
#endif


#ifdef CONFIG_SAVE_PULSE_LOGS
void save_pulse_log(std::string message){
    std::ofstream pulse_log_file;
    pulse_log_file.open(CONFIG_PULSE_LOG_FILE_NAME, std::ios::app);
    pulse_log_file << message << std::endl;
    pulse_log_file.close();
}
#else
void save_pulse_log(std::string message){}
#endif


#ifdef CONFIG_SHOW_PULSES
void pulse_log(std::string message){
    std::cout << "\033[1;34m[ PULSE ]\t\033[0m " << message << std::endl;
    save_pulse_log("PULSE: " + message);
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
        save_pulse_log("REGISTER: " + message);
    } else if (type == "PULSE"){
        pulse_log(message);
    } else if (type == "LOST"){
        std::cout << "\033[1;31m[ LOST ]\t\033[0m " << message << std::endl;
        save_pulse_log("LOST: " + message);
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


}
#endif

