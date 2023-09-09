#include <iostream>
#include <vector>

struct CardPair {
    std::string card1, card2;
};

bool isEqual(const CardPair &cardPair) {
    return cardPair.card1[0] == cardPair.card2[0];
}

int main() {
    std::vector<std::string> all_cards {
            "2S", "2C", "2D", "2H",
            "3S", "3C", "3D", "3H",
            "4S", "4C", "4D", "4H",
            "5S", "5C", "5D", "5H",
            "6S", "6C", "6D", "6H",
            "7S", "7C", "7D", "7H",
            "8S", "8C", "8D", "8H",
            "9S", "9C", "9D", "9H",
            "TS", "TC", "TD", "TH",
            "JS", "JC", "JD", "JH",
            "QS", "QC", "QD", "QH",
            "KS", "KC", "KD", "KH",
            "AS", "AC", "AD", "AH",
    };


    std::size_t tests_count;
    std::cin >> tests_count;



    std::size_t players_count;
    for (std::size_t i = 0; i != tests_count; ++i) {
        std::cin >> players_count;
        std::vector<CardPair> player_cards(players_count);
        for (auto &cards : player_cards) {
            std::cin >> cards.card1 >> cards.card2;

        }


    }
}