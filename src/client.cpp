/**
 * Network Pulse
 * A simple arp table like tool to see if clients are connected and alive on the network.
 * GitHub: https://www.github.com/0x4248/NetworkPulse
 * Licence: GNU General Public License v3.0
 * By: 0x4248
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
#include <ctime>

#include "os.h"
#include "hostname.h"
#include "config.h"
#include "version.h"


/**
 * Main function for client
 * @param argc Number of arguments passed to program
 * @param argv Arguments passed to program
 * @return Exit code
*/
int main(int argc, char *argv[]) {
    std::cout << "NetworkPulse Client" << " (" << VERSION << "." << PATCH << "." << SUBLEVEL << ")\n";
    std::string pulse_server = CONFIG_DEFAULT_SERVER_IP;
    int pulse_port = CONFIG_DEFAULT_PORT;
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
            std::cerr << "Error connecting to server... will try again in " << CONFIG_RETRY_TIMEOUT << " seconds.\n";
            sleep(CONFIG_RETRY_TIMEOUT);
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
        sleep(CONFIG_PULSE_PING_INTERVAL);
    }
}
