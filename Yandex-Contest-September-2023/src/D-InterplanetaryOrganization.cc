//
//  Time-limit-exceeded on last test when 'n' is 1kk
//

#include <bits/stdc++.h>

std::vector<int> DFS_document(const std::vector<int> &document, const std::vector<char> &languages, int n) {
    if (document.size() == 2)
        return {};

    std::stack<std::pair<int, int>> s;
    std::vector<int> distances(n, -1);
    std::vector<bool> visited(n + 1, false);
    std::vector<std::pair<int, int>> order;
    order.reserve(n);
    visited[0] = true;

    s.emplace(0, document.size());

    int start, saved;
    while (!s.empty()) {
        auto borders = s.top();

        bool is_found = false;

        for (int i = borders.first; i != borders.second; ++i) {
            if (visited[document[i]])
                continue;

            saved = document[i], start = i;
            while (document[++i] != saved);

            s.emplace(start, i);
            visited[saved] = is_found = true;

            if (document[borders.first] == 0) {
                order.emplace_back(0, 0);
                distances[saved - 1] = 0;
                break;
            }

            if (languages[document[borders.first] - 1] == 'B') {
                order.emplace_back(order.back().first + 1, 0);
            } else {
                order.emplace_back(0, order.back().second + 1);
            }

            distances[saved - 1] = languages[saved - 1] == 'A' ? order.back().first : order.back().second;
            break;
        }

        if (!is_found) {
            s.pop();
            order.pop_back();
        }
    }

    return distances;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<char> languages(n);
    for (auto &item : languages)
        std::cin >> item;

    std::vector<int> document(2 * n + 2);
    for (auto &item : document)
        std::cin >> item;

    auto distances = DFS_document(document, languages, n);

    for (auto item : distances)
        std::cout << item << ' ';
    std::cout << std::endl;

    return EXIT_SUCCESS;
}



/*
1)
10
A B B A B A B A B A
0 1 2 4 5 5 4 2 3 6 6 3 1 7 8 9 9 10 10 8 7 0

0 1 1 1 1 1 0 1 1 0

2)
5
A B A A B
0 1 2 2 3 4 4 5 5 3 1 0

0 1 0 0 2

3)
5
A A B B B
0 1 1 2 3 3 4 5 5 4 2 0

0 0 1 1 0

4)
5
A B B A B
0 1 1 2 3 4 4 5 5 3 2 0
0 0 0 2 0

5)
15
A B A B B A B A B A B A A B A
0 1 2 4 6 9 10 11 11 12 12 10 9 6 7 7 4 5 8 8 5 2 3 3 1 13 14 14 15 15 13 0

0 1 0 0 0 2 0 2 1 1 1 0 0 1 0

6)
7
B B B B B B A
0 1 2 3 4 5 6 7 7 6 5 4 3 2 1 0
0 0 0 0 0 0 6

7)

8
B B B B B B A A
0 1 2 3 4 5 6 7 7 8 8 6 5 4 3 2 1 0

a: 0 0 0 0 0 0 6 6

*/