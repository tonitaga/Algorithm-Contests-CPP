#include <iostream>

int main() {
    std::string main_string;
    std::cin >> main_string;

    std::size_t swaps_count;
    std::cin >> swaps_count;

    std::size_t start, end;
    std::string swapping;
    for (std::size_t i = 0; i != swaps_count; ++i) {
        std::cin >> start >> end >> swapping;
        --start, --end;

        main_string.replace(start, end - start + 1, swapping);
    }

    std::cout << main_string << std::endl;
    return 0;
}