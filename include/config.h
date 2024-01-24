/**
 * Network Pulse
 * A simple arp table like tool to see if clients are connected and alive on the network.
 * GitHub: https://www.github.com/lewisevans2007/NetworkPulse
 * Licence: GNU General Public License v3.0
 * By: Lewis Evans
 *
 * Main configuration file.
 * 
 * DO NOT JUST EDIT THIS FILE.
 * 
 * Its better if you use make menuconfig to generate 
 * config. Then you are less likely to screw something
 * up. This file also contains the deafult configuration
 * just incase someone building this project cant install
 * LibKconfig.
 * 
 * After running make menuconfig these comments will be gone.
 */


// Default port
#define CONFIG_DEFAULT_PORT 2002

// Default server IP
#define CONFIG_DEFAULT_SERVER_IP "192.168.1.1"

// Logging
#define CONFIG_ENABLE_LOGGING 1
#define CONFIG_SHOW_PULSES 1
#define CONFIG_SAVE_PULSE_LOGS 1
#define CONFIG_PULSE_LOG_FILE_NAME 1

// Pulse table
#define CONFIG_PULSE_TABLE 1
#define CONFIG_PULSE_TABLE_FILE_NAME "pulse_table"

// Server config
#define CONFIG_SERVER_PORT 2002

//version
#define VERSION