#pragma once
#ifndef intrusion_terminal_hpp
#define intrusion_terminal_hpp

#include "../../intrusion.hpp"

struct Command {
    std::string full_name;
    std::string term_name; // `cls` let's say, for "clear screen" on Windows
    std::string description = "";
    std::function<void()> action;
    std::optional<bool> is_disabled = false; // does not apply if running as root
    std::optional<int> permission_integer = 3; // `3` for `all`, `2` for authorised user, `1` for admin/sudo, `0` for root
    Command(std::string full_name,
            std::string term_name,
            std::string description,
            std::function<void()> action,
            std::optional<bool> is_disabled,
            std::optional<int> permission_integer)
           : full_name(full_name),
             term_name(term_name),
             description(description),
             action(action),
             is_disabled(is_disabled),
             permission_integer(permission_integer) {}
};

struct Terminal {
    std::vector<Command> commands;
    std::string config_path_in_pak;
    Terminal(std::vector<Command> commands,
             std::string config_path_in_pak)
            : commands(commands),
              config_path_in_pak(config_path_in_pak)
              {
                if (!fs::exists(config_path_in_pak)) throw std::runtime_error("Error: Terminal does not exist inside Intrusion resource pack files");
              }
};

#endif