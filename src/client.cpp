/**
 * Network Pulse
 * A simple arp table like tool to see if clients are connected and alive on the network.
 * GitHub: https://www.github.com/lewisevans2007/NetworkPulse
 * Licence: GNU General Public License v3.0
 * By: Lewis Evans
 * 
 * Client source file
*/

#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <vector>
#include <string>
#include <cstring>
#include <ifaddrs.h>

#include "os.h"
#include "hostname.h"

int main(int argc, char *argv[]) {
    std::cout << "NetworkPulse Client" << std::endl;
    std::string pulse_server = "192.168.1.1";
    int pulse_port = 2002;
    for (int i = 0; i < argc; i++){
        if (strcmp(argv[i], "-s") == 0){
            if (i + 1 < argc){
                pulse_server = argv[i + 1];
            }
        } else if (strcmp(argv[i], "-p") == 0){
            if (i + 1 < argc){
                pulse_port = std::stoi(argv[i + 1]);
            }
        }
    }
    int clientSocket;
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        std::cerr << "Error creating socket.\n";
        return 1;
    }
    
    while (true) {
        clientSocket = socket(AF_INET, SOCK_STREAM, 0);
        sockaddr_in serverAddress{};
        serverAddress.sin_family = AF_INET;
        serverAddress.sin_port = htons(pulse_port);
        inet_pton(AF_INET, pulse_server.c_str(), &serverAddress.sin_addr);

        if (connect(clientSocket, (sockaddr *) &serverAddress, sizeof(serverAddress)) == -1) {
            std::cerr << "Error connecting to server... will try again in 2 seconds.\n";
            sleep(2);
            continue;
        }

        std::time_t current_time = std::time(nullptr);
        std::string data = "NETPULSE," + get_hostname() + "," + OS + "," + std::to_string(current_time);

        int sendResult = send(clientSocket, data.c_str(), data.size() + 1, 0);
        if (sendResult == -1) {
            std::cerr << "Error sending data to server.\n";
            return 1;
        }

        close(clientSocket);
        sleep(1);
    }
}
