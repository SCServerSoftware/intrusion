#pragma once
#ifndef intrusion_file_hpp
#define intrusion_file_hpp

#include "../../intrusion.hpp"

struct File {
    std::string name;
    std::string description;
    std::optional<std::string> password;
    int size;
    std::string path_in_pak;
    std::vector<char> contents;
    std::optional<int> permission_integer = 3; // `3` for `all`, `2` for authorised user, `1` for admin/sudo, `0` for root
    File(std::string name,
         std::string description,
         std::optional<std::string> password = std::nullopt,
         std::string path_in_pak,
         std::optional<int> permission_integer)
        : name(name),
          description(description),
          password(password),
          path_in_pak(path_in_pak),
          permission_integer(permission_integer)
          {
            if (!fs::exists(path_in_pak)) throw std::runtime_error("Error: File does not exist inside Intrusion resource pack files");
          }
};

#endif