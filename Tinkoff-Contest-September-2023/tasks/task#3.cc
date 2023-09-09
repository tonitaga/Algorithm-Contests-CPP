#include <bits/stdc++.h>

int main() {
    std::size_t cards_in_sequence;
    std::cin >> cards_in_sequence;

    std::vector<int> djo_cards_sequence(cards_in_sequence);
    std::vector<int> win_sequence(cards_in_sequence);

    for (auto &item : djo_cards_sequence)
        std::cin >> item;
    for (auto &item : win_sequence)
        std::cin >> item;

    if (djo_cards_sequence == win_sequence) {
        std::cout << "YES" << std::endl;
        return EXIT_SUCCESS;
    }

    int left = 0, right = static_cast<int>(cards_in_sequence) - 1;

    while (djo_cards_sequence[left] == win_sequence[left] and left <= right) ++left;
    while (djo_cards_sequence[right] == win_sequence[right] and right >= left) --right;

    auto left_border = djo_cards_sequence.begin() + left;
    auto right_border = djo_cards_sequence.begin() + right + 1;

    std::sort(left_border, right_border);

    std::string answer = djo_cards_sequence == win_sequence ? "YES" : "NO";
    std::cout << answer << std::endl;

    return EXIT_SUCCESS;
}
