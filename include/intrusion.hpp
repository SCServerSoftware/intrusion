#pragma once
#ifndef intrusion_hpp
#define intrusion_hpp

#include <string>
#include <vector>
#include <optional>
#include <variant>
#include <filesystem>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <unordered_map>
#include <cctype>
#include <regex>
#include <random>
#include <ctime>

namespace fs = std::filesystem;

#include "classes/common/cfg.hpp"
#include "classes/common/etc.hpp"
#include "classes/common/file.hpp"
#include "classes/common/folder.hpp"
#include "classes/common/hexlock.hpp"
#include "classes/common/network.hpp"
#include "classes/common/system.hpp"
#include "classes/common/terminal.hpp"
#include "classes/common/functions/conversions.hpp"

#endif