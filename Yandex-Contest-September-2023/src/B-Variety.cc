#include <bits/stdc++.h>

int main() {
    int N, M, Q;
    std::cin >> N >> M >> Q;

    std::unordered_map<int, int> A, B;
    int variety = 0;
    {
        int item;
        for (int i = 0; i != N; ++i) {
            std::cin >> item;
            A[item]++;
        }
        variety = static_cast<int>(A.size());

        for (int i = 0; i != M; ++i) {
            std::cin >> item;

            int was = std::abs(A[item] - B[item]);
            B[item]++;

            int left = std::abs(A[item] - B[item]);

            if (was > left) {
                variety--;
            } else {
                if (left != 0) variety++;
                else variety--;
            }
        }
    }

    std::vector<int> answers(Q, 0);

    int type, card;
    char player;
    for (int i = 0; i != Q; ++i) {
        std::cin >> type >> player >> card;

        int was = std::abs(A[card] - B[card]);

        if (player == 'A') {
            if (type == 1) A[card]++;
            else           A[card]--;
        } else {
            if (type == 1) B[card]++;
            else           B[card]--;
        }

        int left = std::abs(A[card] - B[card]);

        if (was > left) {
            variety--;
        } else {
            if (left != 0) variety++;
            else variety--;
        }

        answers[i] = variety;
    }

    for (auto item : answers)
        std::cout << item << ' ';
    std::cout << std::endl;

    return EXIT_SUCCESS;
}


// Time complex: O(Q)