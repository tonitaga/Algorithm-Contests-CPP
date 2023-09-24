#include <bits/stdc++.h>

using uint64 = unsigned long long;

void Solution() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    uint64 n, k;
    fin >> n >> k;

    std::vector<uint64> heights(n);

    for (auto &item : heights)
        fin >> item;

    std::sort(heights.begin(), heights.end());
    uint64 min_difference = std::numeric_limits<uint64>::max();

    std::ptrdiff_t left = k, right = 0;
    while (left >= 0) {
        auto min = *(heights.begin() + left);
        auto max = *(heights.rbegin() + right);
        auto tmp_difference = max - min;

        min_difference = std::min(min_difference, tmp_difference);

        left--;
        right++;
    }

    fout << min_difference << std::endl;
    fin.close(), fout.close();
}

int main() {
    Solution();
    return EXIT_SUCCESS;
}