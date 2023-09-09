#include <bits/stdc++.h>

std::unordered_map<int, std::vector<int>> BFS_document(const std::vector<int> &document, const std::vector<char> &languages) {
    std::unordered_map<int, std::vector<int>> map;
    std::queue<std::vector<int>> q;

    if (document.size() == 2)
        return {};

    int start, saved;
    for (int i = 1; i != document.size() - 1; ++i) {
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

        for (int i = 1; i != sub_arr.size() - 1; ++i) {
            saved = sub_arr[i], start = i;
            while (sub_arr[++i] != saved);
            q.emplace(sub_arr.begin() + start, sub_arr.begin() + 1 + i);
            map[current_id].push_back(q.back()[0]);
        }
    }

    return map;
}

std::vector<int> DFS_hierarchy(std::unordered_map<int, std::vector<int>> &hierarchy, const std::vector<char> &lang, int n) {
    if (n == 0) return {};

    std::vector<int> answer(n, 0);
    std::vector<bool> visited(n + 1, false);
    std::stack<int> s;

    s.push(0);
    visited[0] = true;

    std::vector<int> enter_order;



    while (!s.empty()) {
        auto from = s.top();
        bool is_found = false;

        for (auto to : hierarchy[from]) {
            if (!visited[to]) {
                is_found = visited[to] = true;
                s.push(to);
                enter_order.emplace_back(to);
                break;
            }
        }

        if (!is_found) {
            s.pop();
        }
    }

    return enter_order;
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

    auto hierarchy = BFS_document(document, languages);
    auto answer = DFS_hierarchy(hierarchy, languages, n);

    for (auto item : answer)
        std::cout << item << ' ';
    std::cout << std::endl;

    return EXIT_SUCCESS;
}