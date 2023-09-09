#include <bits/stdc++.h>

int main() {
    std::size_t weapons_count, money_count;
    std::cin >> weapons_count >> money_count;

    std::vector<int> weapons_cost(weapons_count);
    for (auto &cost : weapons_cost)
        std::cin >> cost;

    int max = 0;

    for (auto cost : weapons_cost)
        if (cost > max and cost <= static_cast<int>(money_count))
            max = cost;

    std::cout << max << std::endl;

    return EXIT_SUCCESS;
}