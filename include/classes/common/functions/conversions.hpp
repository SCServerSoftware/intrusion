#pragma once
#ifndef intrusion_common_conversions_hpp
#define intrusion_common_conversions_hpp

#include "../../../intrusion.hpp"

Operating_System os_string_to_enum(std::string os) {
    std::transform(os.begin(), os.end(), os.begin(), ::tolower);
    if (os == "windows") return WINDOWS;                        if (os == "macos") return MACOS;
    if (os == "unix") return UNIX;                              if (os == "freebsd") return FREEBSD;
    if (os == "openbsd") return OPENBSD;                        if (os == "netbsd") return NETBSD;
    if (os == "nextstep") return NEXTSTEP;                      if (os == "debian") return DEBIAN;
    if (os == "ubuntu") return UBUNTU;                          if (os == "kali_linux") return KALI_LINUX;
    if (os == "linux_mint") return LINUX_MINT;                  if (os == "raspberry_pi_os") return RASPBERRY_PI_OS;
    if (os == "rhel") return RHEL;                              if (os == "centos") return CENTOS;
    if (os == "centos_stream") return CENTOS_STREAM;            if (os == "fedora") return FEDORA;
    if (os == "rocky_linux") return ROCKY_LINUX;                if (os == "arch") return ARCH;
    if (os == "manjaro") return MANJARO;                        if (os == "endeavouros") return ENDEAVOUROS;
    if (os == "garuda") return GARUDA;                          if (os == "arco_linux") return ARCO_LINUX;
    if (os == "gentoo") return GENTOO;                          if (os == "chromium_os") return CHROMIUM_OS;
    if (os == "google_chrome_os") return GOOGLE_CHROME_OS;      if (os == "opensuse") return OPENSUSE;
    if (os == "opensuse_leap") return OPENSUSE_LEAP;            if (os == "opensuse_tumbleweed") return OPENSUSE_TUMBLEWEED;
    if (os == "gecko_linux") return GECKO_LINUX;                if (os == "slackware") return SLACKWARE;
    if (os == "void_linux") return VOID_LINUX;                  if (os == "alpine_linux") return ALPINE_LINUX;
    if (os == "nixos") return NIXOS;                            if (os == "solus") return SOLUS;
    if (os == "clear_linux") return CLEAR_LINUX;                if (os == "bedrock_linux") return BEDROCK_LINUX;
    if (os == "knoppix") return KNOPPIX;                        if (os == "devuan") return DEVUAN;
    if (os == "lfs") return LFS;                                if (os == "haiku") return HAIKU;
    if (os == "ibm_os_2") return IBM_OS_2;                      if (os == "ibm_os_2_warp") return IBM_OS_2_WARP;
    if (os == "ibm_os_2_warp_2") return IBM_OS_2_WARP_2;        if (os == "solaris") return SOLARIS;
    if (os == "ms_dos") return MS_DOS;                          if (os == "pc_dos") return PC_DOS;
    if (os == "freedos") return FREEDOS;                        if (os == "templeos") return TEMPLEOS;
}

IP_Address ip_string_to_ip(std::string& l, std::string& value) {
    size_t coord = l.find('.');
    std::vector<int> coords;
    size_t start = 0;
    size_t end;
    while ((end = value.find('.', start)) != std::string::npos) {
        coords.push_back(std::stoi(value.substr(start, end - start)));
        start = end + 1;
    }
    coords.push_back(std::stoi(value.substr(start)));
    IP_Address ip_address(coords);
    return ip_address;
}

std::vector<Credentials> populate_credentials(std::string& l) {
    std::vector<Credentials> creds;
    
    std::regex credsPattern(R"(\[([^\]]+),([^\]]+)\])");
    auto credsBegin = std::sregex_iterator(l.begin(), l.end(), credsPattern);
    auto credsEnd = std::sregex_iterator();

    for (std::sregex_iterator i = credsBegin; i != credsEnd; ++i) {
        std::smatch match = *i;
        std::string username = match[1].str();
        std::string password = match[2].str();
        creds.emplace_back(username, password);
    }
    
    return creds;
}

#endif