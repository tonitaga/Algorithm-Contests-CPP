#include <bits/stdc++.h>

void Solution() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    unsigned N;
    fin >> N;

    std::unordered_map<unsigned, unsigned> depth_map;
    unsigned max_depth = 0, max_depth_id = 0;

    for (unsigned i = 1, base = 0; i != N + 1; ++i) {
        fin >> base;
        auto &current_depth = depth_map[i];

        current_depth = depth_map[base] + 1;

        if (current_depth > max_depth) {
            max_depth = current_depth;
            max_depth_id = i;
        }
    }

    fout << max_depth_id;
    fin.close(), fout.close();
}

int main() {
    Solution();
    return EXIT_SUCCESS;
}