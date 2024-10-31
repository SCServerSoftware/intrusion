#pragma once
#ifndef intrusion_hexlock_hpp
#define intrusion_hexlock_hpp

#include "../../intrusion.hpp"

#define hex_lock_table std::vector<std::vector<int>>

hex_lock_table generate_hlt(int level) {
    hex_lock_table hl;
    std::random_device rd;
    std::mt19937_64 mt;
}

#endif