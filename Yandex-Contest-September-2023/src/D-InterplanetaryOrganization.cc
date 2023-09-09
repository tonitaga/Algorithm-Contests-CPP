#include <bits/stdc++.h>

std::unordered_map<int, std::vector<int>> BFS_document(const std::vector<int> &document) {
    std::unordered_map<int, std::vector<int>> map;
    std::queue<std::vector<int>> q;

    if (document.size() == 2)
        return {};

    int start, saved;
    for (std::size_t i = 1; i != document.size() - 1; ++i) {
        saved = document[i], start = i;
        while (document[++i] != saved);
        q.emplace(document.begin() + start, document.begin() + 1 + i);
        map[0].push_back(q.back()[0]);
    }

    int current_id;
    while (!q.empty()) {
        auto sub_arr = q.front();
        q.pop();
        current_id = sub_arr[0];

        map[current_id];

        if (sub_arr.size() == 2)
            continue;

        for (std::size_t i = 1; i != sub_arr.size() - 1; ++i) {
            saved = sub_arr[i], start = i;
            while (sub_arr[++i] != saved);
            q.emplace(sub_arr.begin() + start, sub_arr.begin() + 1 + i);
            map[current_id].push_back(q.back()[0]);
        }
    }

    return map;
}

//std::vector<int> DFS_hierarchy(std::unordered_map<int, std::vector<int>> &hierarchy, const std::vector<char> &lang, int n) {
//    if (n == 0)
//        return {};
//
//    std::stack<int> s;
//    s.push(0);
//
//    std::vector<bool> visited(n + 1, false);
//    visited[0] = true;
//
//    int left_id = hierarchy[0].front(), right_id = hierarchy[0].back();
//    int distance_to_a = 0, distance_to_b = 0;
//    int saved_distance_b = 0, saved_distance_a = 0;
//    bool a_was_incremented = false, b_was_incremented = false;
//
//    std::vector<int> distances(n, -1);
//
//    while (!s.empty()) {
//        auto from = s.top();
//
//        if (from == left_id or from == right_id)
//            distance_to_b = distance_to_a = 0;
//
//        bool is_found = false;
//
//
//        for (auto sub_item : hierarchy[from]) {
//            if (visited[sub_item])
//                continue;
//
//            is_found = true;
//            s.push(sub_item);
//            visited[sub_item] = true;
//
//            if (from == 0) {
//                distances[sub_item - 1] = 0;
//            } else if (lang[sub_item - 1] != lang[from - 1]) {
//                if (lang[sub_item - 1] == 'A') {
//                    distance_to_a++;
//                    saved_distance_a = distance_to_a;
//                    a_was_incremented = true;
//                    distances[sub_item - 1] = distance_to_a;
//                    distance_to_a = 0;
//                } else {
//                    distance_to_b++;
//                    saved_distance_b = distance_to_b;
//                    b_was_incremented = true;
//                    distances[sub_item - 1] = distance_to_b;
//                    distance_to_b = 0;
//                }
//            } else {
//                if (lang[sub_item - 1] == 'A') {
//                    b_was_incremented = true;
//                    distance_to_b++;
//                    saved_distance_b = distance_to_b;
//                    distance_to_a = 0;
//                } else {
//                    a_was_incremented = true;
//                    distance_to_a++;
//                    saved_distance_a = distance_to_a;
//                    distance_to_b = 0;
//                }
//                distances[sub_item - 1] = 0;
//            }
//
//            break;
//        }
//
//        if (!is_found) {
//            s.pop();
//
//
//            if (b_was_incremented) {
//                saved_distance_b--;
//                distance_to_b = saved_distance_b;
//            }
//            if (a_was_incremented) {
//                saved_distance_a--;
//                distance_to_a = saved_distance_a;
//            }
//
//            a_was_incremented = false, b_was_incremented = false;
//        }
//    }
//
//    return distances;
//}

std::vector<int> DFS_hierarchy(std::unordered_map<int, std::vector<int>> &hierarchy, const std::vector<char> &languages, int n) {
    std::vector<char> order;
    order.reserve(hierarchy.size() * 2);
    order.push_back('\0'); // '\0' means that is start (head) of hierarchy

    std::stack<int> s;
    s.push(0); // starting from head of hierarchy

    std::vector<bool> visited(n + 1, false);
    visited[0] = true; // at start head is visited;

    std::vector<int> distances(n, -1); // array of distances

    while (!s.empty()) {
        int from = s.top();

        bool is_found = false;
        for (auto sub_item : hierarchy[from]) {
            if (visited[sub_item])
                continue;

            is_found = true;
            s.push(sub_item);
            visited[sub_item] = true;
            order.push_back(languages[sub_item - 1]);

            int distance = 0;
            for (auto it = order.rbegin() + 1; it != order.rend(); ++it) {
                if (languages[sub_item - 1] != *it) distance++;
                else break;

                if (*it == '\0') distance--;
            }

            distances[sub_item - 1] = distance;
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

    auto hierarchy = BFS_document(document);
    auto distances = DFS_hierarchy(hierarchy, languages, n);

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