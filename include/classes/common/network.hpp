#pragma once
#ifndef intrusion_network_hpp
#define intrusion_network_hpp

#include "../../intrusion.hpp"

struct Network {
    std::string name;
    std::string information;
    IP_Address ip;
    std::vector<Credentials> valid_credentials = {};
    std::vector<System> systems = {};
    Network(std::string name,
            std::string information,
            IP_Address ip,
            std::vector<Credentials> valid_credentials,
            std::vector<System> systems)
            : name(name),
              information(information),
              ip(ip),
              valid_credentials(valid_credentials),
              systems(systems)
              {
                if (systems.empty()) printf("Warning: No systems found in network");
                if (valid_credentials.empty()) printf("Warning: Network has no set of valid credentials. It will be treated as open.");
              }
};

#endif