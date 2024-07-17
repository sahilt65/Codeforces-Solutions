#include <iostream>
#include <regex>
#include<bits/stdc++.h>
using namespace std;

std::string validate_ip_address(const std::string& ip) {
    // Regular expressions for IPv4 and IPv6
    std::regex ipv4_pattern(R"((\d{1,3}\.){3}\d{1,3})");
    std::regex ipv6_pattern(R"([0-9a-fA-F:]+)");

    if (std::regex_match(ip, ipv4_pattern)) {
        // Further validation to ensure each segment is between 0 and 255
        stringstream ss(ip);
        string segment;
        bool valid = true;
        while (std::getline(ss, segment, '.')) {
            int part = std::stoi(segment);
            if (part < 0 || part > 255) {
                valid = false;
                break;
            }
        }
        if (valid) {
            return "IPv4";
        }
    }

    if (std::regex_match(ip, ipv6_pattern)) {
        // Further validation to ensure the address conforms to IPv6 standards
        std::stringstream ss(ip);
        std::string segment;
        int count = 0;
        while (std::getline(ss, segment, ':')) {
            count++;
        }
        if (count <= 8) {
            return "IPv6";
        }
    }

    return "Neither";
}

int main() {
    std::cout << validate_ip_address("192.168.1.1") << std::endl;    // Output: IPv4
    std::cout << validate_ip_address("2001:0db8:85a3:0000:0000:8a2e:0370:7334") << std::endl;  // Output: IPv6
    std::cout << validate_ip_address("256.256.256.256") << std::endl; // Output: Neither
    std::cout << validate_ip_address("1234:5678:9abc:def::1234") << std::endl; // Output: IPv6
    std::cout << validate_ip_address("not an IP address") << std::endl; // Output: Neither

    return 0;
}
