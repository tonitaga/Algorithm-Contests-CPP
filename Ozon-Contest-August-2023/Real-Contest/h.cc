#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <sstream>

struct IP {
    int x, y;
};

std::vector<IP> parseIPs(const std::vector<std::string>& ips) {
    std::vector<IP> parsedIPs;
    for (const auto& ip : ips) {
        std::stringstream ss(ip);
        std::string segment;
        std::vector<std::string> segments;
        while (std::getline(ss, segment, '.')) {
            segments.push_back(segment);
        }
        if (segments.size() == 4) {
            parsedIPs.push_back({std::stoi(segments[2]), std::stoi(segments[3])});
        }
    }
    return parsedIPs;
}

std::string getSubnet(const IP& ip) {
    return "100.200." + std::to_string(ip.x) + ".0/24";
}

std::string getIP(const IP& ip) {
    return "100.200." + std::to_string(ip.x) + "." + std::to_string(ip.y);
}

std::vector<std::string> generateFilterFile(const std::vector<IP>& blackList, int maxEntries) {
    std::vector<std::string> filterFile;
    std::bitset<256> subnetUsed;
    std::bitset<65536> ipUsed;
    int entries = 0;
    for (const auto& ip : blackList) {
        if (!subnetUsed[ip.x]) {
            subnetUsed[ip.x] = true;
            filterFile.push_back(getSubnet(ip));
            entries++;
            if (entries >= maxEntries) {
                break;
            }
        }
        if (!ipUsed[ip.x * 256 + ip.y]) {
            ipUsed[ip.x * 256 + ip.y] = true;
            filterFile.push_back(getIP(ip));
            entries++;
            if (entries >= maxEntries) {
                break;
            }
        }
    }
    return filterFile;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::string> blackList(n);
    for (int i = 0; i < n; i++) {
        std::cin >> blackList[i];
    }

    std::vector<IP> parsedIPs = parseIPs(blackList);
    std::vector<std::string> filterFile = generateFilterFile(parsedIPs, k);

    std::cout << 256 - parsedIPs.size() << std::endl;
    std::cout << filterFile.size() << std::endl;
    for (const auto& entry : filterFile) {
        std::cout << entry << std::endl;
    }

    return 0;
}
