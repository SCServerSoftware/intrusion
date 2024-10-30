#pragma once
#ifndef intrusion_cfg_hpp
#define intrusion_cfg_hpp

#include "../../intrusion.hpp"

struct Config_Entry {
    std::string key;
    std::string value;
    Config_Entry(std::string key,
                std::string value)
               : key(key),
                 value(value) {}
};

#define Config_Table std::vector<Config_Entry>

#endif