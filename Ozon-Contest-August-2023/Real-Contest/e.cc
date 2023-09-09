#include <iostream>
#include <vector>
#include <set>

int main() {
    // Input and prepare data for work part BEGIN
    std::size_t friends_count, cards_count;
    std::cin >> friends_count >> cards_count;

    std::vector<std::size_t> friends(friends_count);
    std::size_t min = cards_count + 1, max = 0, max_index = 0;

    for (std::size_t i = 0; i != friends_count; ++i) {
        std::cin >> friends[i];

        if (friends[i] > max) {
            max = friends[i];
            max_index = i;
        }

        if (friends[i] <= min) {
            min = friends[i];
        }
    }

    std::set<std::size_t> existed_cards;
    std::vector<std::size_t> visited(cards_count - min, 0);

    for (std::size_t i = min + 1; i <= cards_count; ++i) {
        existed_cards.insert(i);
    }

    std::vector<std::size_t> answers(friends_count, 0);
    for (std::size_t i = 0; i != friends_count; ++i) {
        auto it_s = existed_cards.begin();
        auto it_v = visited.begin();

        while (it_s != existed_cards.end()) {
            if (*it_v == 0 and *it_s > friends[i]) {
                if (*it_s == max + 1 and i < max_index) {
                    std::cout << -1 << std::endl;
                    return 0;
                }
                answers[i] = *it_s;
                *it_v = 1;
                break;
            }
            ++it_s, ++it_v;
        }

        if (answers[i] == 0) {
            std::cout << -1 << std::endl;
            return 0;
        }
    }

    for (const auto &i : answers)
        std::cout << i << ' ';
    std::cout << '\n';
    return 0;
}