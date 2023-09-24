#include <bits/stdc++.h>

using uint64 = unsigned long long;

void Solution() {
    uint64 n, m, c2, c5;
    std::cin >> n >> m >> c2 >> c5;

    if (n >= m) {
        std::cout << 0 << std::endl;
        return;
    }

    auto cost_per_usb_port_c2 = static_cast<double>(c2);
    auto cost_per_usb_port_c5 = static_cast<double>(c5) / 4.;
    uint64 difference = m - n;

    unsigned long long cost = 0;
    if (cost_per_usb_port_c2 <= cost_per_usb_port_c5) {
        uint64 need_posts = difference;
        cost = need_posts * c2;
    } else {
        uint64 need_post_c5 = difference / 4;
        cost = need_post_c5 * c5;

        uint64 last_need_ports = difference - need_post_c5 * 4;
        cost += std::min(c5, c2 * last_need_ports);
    }

    std::cout << cost << std::endl;
}

int main() {
    Solution();
    return EXIT_SUCCESS;
}