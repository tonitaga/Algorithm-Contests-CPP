#include <bits/stdc++.h>

using uint64 = unsigned long long;

void Solution() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    uint64 k, n, m;
    fin >> k >> n >> m;

    std::unordered_map<uint64, std::list<uint64>> road_in_days;
    uint64 current_executed_roads = 0;

    uint64 day;
    for (uint64 i = 0, road_id; i != n; ++i) {
        fin >> day >> road_id;
        if (road_in_days.find(road_id) == road_in_days.end())
            current_executed_roads++;

        road_in_days[road_id].push_back(day);
    }

    std::unordered_map<uint64, std::list<uint64>> sadness;
    for (auto &[road_id, days] : road_in_days) {
        if (days.empty())
            continue;

        road_in_days[road_id].push_back(day);

        auto prev = days.begin();
        auto start = ++days.begin();
        auto end = days.end();

        while (start != end) {
            sadness[road_id].push_back(*start - *prev);
            prev = start;
            ++start;
        }
    }

    std::list<uint64> all;
    for (auto &[road_id, sadness_vector] : sadness) {
        if (m > 0 and !sadness_vector.empty()) {
            sadness_vector.pop_back();
            --m;
            all.splice(all.end(), sadness_vector);
        } else if (m == 0) {
            fout << -1 << std::endl;
            return;
        }
    }

    all.sort();
    auto last_element = std::prev(all.end(), m);
    auto sum = std::accumulate(all.begin(), last_element, uint64{});
    fout << sum << std::endl;
    fin.close(), fout.close();
}

int main() {
    Solution();
    return EXIT_SUCCESS;
}