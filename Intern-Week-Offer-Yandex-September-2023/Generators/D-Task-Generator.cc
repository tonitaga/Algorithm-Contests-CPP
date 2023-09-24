#include <bits/stdc++.h>

double getProbability() {
    static std::default_random_engine re(std::chrono::system_clock::now().time_since_epoch().count());
    static std::uniform_real_distribution dist(0.0, 1.0);
    return dist(re);
}

int main() {
    std::ofstream file("input.txt");
    if (!file.is_open())
        return EXIT_FAILURE;

    unsigned k = 1'000, n = 1'000'00;

    std::default_random_engine re(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution dist_uint(1u, n);

    unsigned m = 9'000'0;

    dist_uint = std::uniform_int_distribution(1u, k);
    unsigned day = 1;

    file << k << ' ' << n << ' ' << m << '\n';

    std::uniform_int_distribution day_dist(1, 15);

    for (unsigned i = 0, road; i != n; ++i) {
        double probability = getProbability();
        road = dist_uint(re);

        file << day << ' ' << road << '\n';

        if (probability <= 0.35) {}
        else if (probability <= 0.8) { day += 1; }
        else { day += day_dist(re); }
    }

    file.close();
}