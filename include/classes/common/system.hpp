#pragma once
#ifndef intrusion_system_hpp
#define intrusion_system_hpp

#include "../../intrusion.hpp"

IP_Address default_ip({0, 0, 0, 0, 0});

struct System {
    std::string name;
    Operating_System os;
    IP_Address ip = default_ip;
    std::vector<Credentials> valid_credentials = {};
    std::vector<Folder> folders = {};
    // Takes from a config file
    System(std::string config_path) {
        if(!fs::exists(config_path)) throw std::runtime_error("Error: System does not exist inside Intrusion resource pack");
        std::ifstream sysfile(config_path);
        if (!sysfile.is_open()) throw std::runtime_error("Error: Could not open system config file");
        else {
            std::string l;
            Config_Table syscfg;
            while (std::getline(sysfile, l)) {
                size_t delim = l.find(':');
                if (delim != std::string::npos) {
                    std::string key = l.substr(0, delim);
                    std::string value = l.substr(delim + 1);
                    Config_Entry cfg(key, value);
                    syscfg.push_back(cfg);
                    if (key == "name") name = value;
                    if (key == "os") os = os_string_to_enum(value);
                    if (key == "ip") ip = ip_string_to_ip(l, value);
                    
                }
            }
        }
    }
};

#endif