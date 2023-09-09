#include <iostream>
#include <vector>

int main() {
    std::size_t count = 0;
    std::cin >> count;

    std::vector<int> numbers;
    numbers.reserve(count * 2);

    int number1, number2;
    for (std::size_t i = 0; i != count; ++i) {
        std::cin >> number1 >> number2;
        numbers.push_back(number1);
        numbers.push_back(number2);
    }

    for (std::size_t i = 0; i <= numbers.size() - 1; i += 2) {
        std::cout << numbers[i] + numbers[i + 1] << std::endl;
    }
}