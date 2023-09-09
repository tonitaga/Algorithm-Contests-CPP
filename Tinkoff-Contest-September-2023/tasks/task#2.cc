#include <bits/stdc++.h>

struct Less {
    bool operator()(const std::pair<char, int> &lhs,
                    const std::pair<char, int> &rhs) {
        return lhs.second < rhs.second;
    }
};

int main() {
    std::unordered_map<char, int> map;
    std::string message;
    std::cin >> message;

    std::string complete_word = "sherif";

    for (auto letter : message) {
        if (complete_word.find(letter) != std::string::npos)
            ++map[letter];
    }

    map['f'] /= 2;

    if (map.size() != complete_word.size()) {
        std::cout << 0 << std::endl;
        return EXIT_SUCCESS;
    }

    auto answer = *std::min_element(map.begin(), map.end(), Less{});

    std::cout << answer.second << std::endl;
    return EXIT_SUCCESS;
}