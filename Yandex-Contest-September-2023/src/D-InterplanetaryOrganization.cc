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

std::vector<int> DFS_hierarchy(std::unordered_map<int, std::vector<int>> &hierarchy, const std::vector<char> &lang, int n) {
    if (n == 0)
        return {};

    std::stack<int> s;
    s.push(0);

    std::vector<bool> visited(n + 1, false);
    visited[0] = true;

    int left_id = hierarchy[0].front(), right_id = hierarchy[0].back();
    int distance_to_a = 0, distance_to_b = 0;
    bool a_was_incremented = false, b_was_incremented = false;

    std::vector<int> distances(n, -1);

    while (!s.empty()) {
        auto from = s.top();

        if (from == left_id or from == right_id)
            distance_to_b = distance_to_a = 0;

        bool is_found = false;


        for (auto sub_item : hierarchy[from]) {
            if (visited[sub_item])
                continue;

            is_found = true;
            s.push(sub_item);
            visited[sub_item] = true;

            if (from == 0)
                distances[sub_item - 1] = 0;
            else if (lang[sub_item - 1] != lang[from - 1]) {
                if (lang[sub_item - 1] == 'A') {
                    distance_to_a++;
                    a_was_incremented = true;
                    distances[sub_item - 1] = distance_to_a;
                } else {
                    distance_to_b++;
                    b_was_incremented = true;
                    distances[sub_item - 1] = distance_to_b;
                }
            } else {
                if (lang[sub_item - 1] == 'A')
                    b_was_incremented = true, distance_to_b++;
                else
                    a_was_incremented = true, distance_to_a++;
                distances[sub_item - 1] = 0;
            }

            break;
        }

        if (!is_found) {
            s.pop();

            if (b_was_incremented)
                distance_to_b--;
            if (a_was_incremented)
                distance_to_a--;

            a_was_incremented = false, b_was_incremented = false;
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