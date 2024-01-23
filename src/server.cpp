/**
 * Network Pulse
 * A simple arp table like tool to see if clients are connected and alive on the network.
 * GitHub: https://www.github.com/lewisevans2007/NetworkPulse
 * Licence: GNU General Public License v3.0
 * By: Lewis Evans
 * 
 * Server source file
*/

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>
#include <thread>
#include <fstream>

#include "logger.h"
#include "table.h"
#include "config.h"

std::vector<std::string> ip_addresses;
std::vector<std::string> hostnames;
std::vector<std::string> operating_systems;
std::vector<std::string> times_sent;


void register_checker(){
    while (true){
        std::time_t current_time = std::time(nullptr);
        for (int i = 0; i < times_sent.size(); i++){
            int time_sent_int = std::stoi(times_sent[i]);
            if (current_time - time_sent_int > 5){
                log("LOST", "Lost client with IP: " + ip_addresses[i] + " and hostname: " + hostnames[i]);
                ip_addresses.erase(ip_addresses.begin() + i);
                hostnames.erase(hostnames.begin() + i);
                operating_systems.erase(operating_systems.begin() + i);
                times_sent.erase(times_sent.begin() + i);
                update_table(ip_addresses, hostnames, operating_systems, times_sent);
            }
        }
        sleep(1);
    }
}

int main() {
    std::cout << "NetworkPulse Server" << std::endl;
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        std::cerr << "Error creating socket.\n";
        return 1;
    }

    sockaddr_in serverAddress{};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(CONFIG_SERVER_PORT);
    
    init_table();

    if (bind(serverSocket, (sockaddr *) &serverAddress, sizeof(serverAddress)) == -1) {
        std::cerr << "Error binding socket.\n";
        return 1;
    }

    std::thread register_checker_thread(register_checker);
    register_checker_thread.detach();

    while (true) {
        if (listen(serverSocket, SOMAXCONN) == -1) {
            std::cerr << "Error listening.\n";
            return 1;
        }
        sockaddr_in clientAddress{};
        socklen_t clientSize = sizeof(clientAddress);
        int clientSocket = accept(serverSocket, (sockaddr *) &clientAddress, &clientSize);
        if (clientSocket == -1) {
            log("ERROR", "Error accepting connection.");
            return 1;
        }

        char buffer[4096];
        memset(buffer, 0, 4096);
        int bytesReceived = recv(clientSocket, buffer, 4096, 0);
        if (bytesReceived == -1) {
            std::cerr << "Error in recv().\n";
            return 1;
        }

        std::string data = std::string(buffer, bytesReceived);
        std::vector<std::string> data_vector;
        std::string delimiter = ",";
        size_t pos = 0;
        std::string token;
        while ((pos = data.find(delimiter)) != std::string::npos) {
            token = data.substr(0, pos);
            data_vector.push_back(token);
            data.erase(0, pos + delimiter.length());
        }

        data_vector.push_back(data);
        bool found = false;
        std::string IP = inet_ntoa(clientAddress.sin_addr);
        for (int i = 0; i < ip_addresses.size(); i++){
            if (ip_addresses[i] == IP){
                found = true;
                times_sent[i] = data_vector[3];
            }
        }
        if (!found){
            ip_addresses.push_back(IP);
            hostnames.push_back(data_vector[1]);
            operating_systems.push_back(data_vector[2]);
            times_sent.push_back(data_vector[3]);
            log("REGISTER", "Registered client with IP: " + IP + " and hostname: " + data_vector[1]);
            update_table(ip_addresses, hostnames, operating_systems, times_sent);

        } else {
            log("PULSE", "Pulsed client with IP: " + IP + " and hostname: " + data_vector[1]);
            update_table(ip_addresses, hostnames, operating_systems, times_sent);
        }
        close(clientSocket);

    }
}
