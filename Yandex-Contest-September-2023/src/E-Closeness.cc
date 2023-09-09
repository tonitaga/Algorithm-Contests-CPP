#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> arrays;
    {
        int size;
        for (int i = 0; i != n; ++i) {
            std::cin >> size;
            std::vector<int> tmp(size);
            for (auto &item : tmp)
                std::cin >> item;

            arrays.push_back(std::move(tmp));
        }
    }

    int sum = 0;
    for (int i = 0; i != n - 1; ++i) {
        for (int j = i + 1; j != n; ++j) {
            int min_size = static_cast<int>(std::min(arrays[i].size(), arrays[j].size()));
            for (int k = 0; k < min_size; ++k) {
                if (arrays[i][k] == arrays[j][k])
                    sum++;
                else
                    break;
            }
        }
    }

    std::cout << sum << std::endl;

    return EXIT_SUCCESS;
}
