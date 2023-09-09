#include <iostream>
#include <vector>

struct Pair {
    std::size_t min = 0, max = 0;
};

int main() {
    std::size_t tests_count;
    std::cin >> tests_count;

    std::size_t people_count;

    Pair limits {
        .min = 15,
        .max = 30
    };

    std::string prefix;
    std::size_t temperature;
    std::vector<std::vector<int>> numbers;

    for (std::size_t i = 0; i != tests_count; ++i) {
        std::cin >> people_count;
        std::vector<int> number;
        limits = { .min = 15, .max = 30 };
        for (std::size_t j = 0; j != people_count; ++j) {
            std::cin >> prefix >> temperature;
            if (prefix == ">=") {
                if (temperature > limits.min)
                    limits.min = temperature;
            } else {
                if (temperature < limits.max)
                    limits.max = temperature;
            }

            if (limits.min > limits.max)
                number.emplace_back(-1);
            else
                number.emplace_back(static_cast<int>(limits.max));
        }
        numbers.push_back(std::move(number));
    }

    for (const auto &vec : numbers) {
        for (auto item : vec) {
            std::cout << item << '\n';
        }
        std::cout << '\n';
    }
    return 0;
}