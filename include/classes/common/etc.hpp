#pragma once
#ifndef intrusion_common_hpp
#define intrusion_common_hpp

#include "../../intrusion.hpp"

struct Credentials {
    std::string username;
    std::string password;
    int permission_integer = 3; // `3` for `all`, `2` for authorised user, `1` for admin/sudo, `0` for root
    Credentials(std::string username,
                std::string password)
               : username(username),
                 password(password)
                 {
                    for (char c : username) {
                        if (!std::isalnum(c)) {
                            std::string new_username;
                            for (char c2 : username) {
                                if (std::isalnum(c2)) new_username += c2;
                            }
                            if (new_username != username) {
                                printf("Warning: Username had non-alphanumeric character(s), cleaning up to %s\n", new_username.c_str());
                                username = new_username;
                            }
                        }
                    }
                }
};

struct IP_Address {
    int coord1;
    int coord2;
    int coord3;
    int coord4;
    int coord5;
    IP_Address(std::vector<int> coords)
        : coord1(coords[0]),
          coord2(coords[1]),
          coord3(coords[2]),
          coord4(coords[3]),
          coord5(coords[4])
          {
            if (coords.size() < 5) {
                throw std::runtime_error("Error: Invalid IP address");
            } else {
                for (int i = 0; i < coords.size(); i++) {
                    switch (coords[i]) {
                        case 0 ... 255: break;
                        default: throw std::runtime_error("Error: Invalid IP address coordinate found in set "+std::to_string(i)+"("+std::to_string(coords[i])+")");
                    }
                }
            }
          }
};

enum OS_COMMON { WINDOWS, MACOS };
enum OS_UNIX_LIKE {
    UNIX,
    FREEBSD,
    OPENBSD,
    NETBSD,
    NEXTSTEP
};
enum OS_LINUX_DEBIAN_BASED {
    DEBIAN,
    UBUNTU,
    KALI_LINUX,
    LINUX_MINT,
    RASPBERRY_PI_OS
};
enum OS_LINUX_RHEL_BASED {
    RHEL,
    CENTOS,
    CENTOS_STREAM,
    FEDORA,
    ROCKY_LINUX
};
enum OS_LINUX_ARCH_BASED {
    ARCH,
    MANJARO,
    ENDEAVOUROS,
    GARUDA,
    ARCO_LINUX
};
enum OS_LINUX_GENTOO_BASED {
    GENTOO,
    CHROMIUM_OS,
    GOOGLE_CHROME_OS
};
enum OS_LINUX_OPENSUSE_BASED {
    OPENSUSE,
    OPENSUSE_LEAP,
    OPENSUSE_TUMBLEWEED,
    GECKO_LINUX
};
enum OS_LINUX_OTHER {
    SLACKWARE,
    VOID_LINUX,
    ALPINE_LINUX,
    NIXOS,
    SOLUS,
    CLEAR_LINUX,
    BEDROCK_LINUX,
    KNOPPIX,
    DEVUAN,
    LFS
};
enum OS_OTHER {
    HAIKU,
    IBM_OS_2,
    IBM_OS_2_WARP,
    IBM_OS_2_WARP_2,
    SOLARIS,
    MS_DOS,
    PC_DOS,
    FREEDOS,
    TEMPLEOS
};

using Operating_System = std::variant<
    OS_COMMON,
    OS_UNIX_LIKE,
    OS_LINUX_DEBIAN_BASED,
    OS_LINUX_RHEL_BASED,
    OS_LINUX_ARCH_BASED,
    OS_LINUX_GENTOO_BASED,
    OS_LINUX_OPENSUSE_BASED,
    OS_LINUX_OTHER,
    OS_OTHER
>;

#endif