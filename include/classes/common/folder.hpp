#pragma once
#ifndef intrusion_folder_hpp
#define intrusion_folder_hpp

#include "../../intrusion.hpp"

struct Folder {
    std::string name;
    std::vector<File> files = {};
    std::optional<std::string> password;
    int permission_integer = 3; // `3` for `all`, `2` for authorised user, `1` for admin/sudo, `0` for root
    Folder(std::string name,
           std::vector<File> files,
           std::optional<std::string> password = std::nullopt,
           int permission_integer)
        : name(name),
          files(files),
          password(password),
          permission_integer(permission_integer) {}
};

#endif