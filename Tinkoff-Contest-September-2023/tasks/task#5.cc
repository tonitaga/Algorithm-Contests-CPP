#include <bits/stdc++.h>

struct List {
    std::size_t vertex_index = 0;
    std::size_t weight = 0;
};

template <typename T>
using AdjacencyList = std::vector<std::vector<List>>;

std::size_t BFS(const AdjacencyList<std::size_t> &adjacency_list, std::size_t exist_weight, bool is_need_constraint_weight = true) {
    std::vector<std::size_t> enter_order;
    std::vector<bool> visited(adjacency_list.size(), 0);

    std::queue<std::size_t> q;
    visited[0] = true;
    q.push(0);
    enter_order.push_back(0);

    std::size_t count = 0;

    while (std::all_of(visited.begin(), visited.end(), [](auto item) { return item != true; })) {
        ++count;
        while (!q.empty()) {
            std::size_t from = q.front();
            q.pop();

            for (const auto &to: adjacency_list[from]) {
                if (visited[to.vertex_index])
                    continue;

                bool need_push = false;

                if ((is_need_constraint_weight and to.weight > exist_weight) or !is_need_constraint_weight)
                    need_push = true;

                if (need_push) {
                    visited[to.vertex_index] = true;
                    q.push(to.vertex_index);
                    enter_order.push_back(to.vertex_index);
                }
            }
        }

        for (std::size_t i = 0; i != visited.size(); ++i)
            if (!visited[i]) {
                q.push(i);
                break;
            }
    }

    return count;
}

int main() {
    std::size_t vertexes_count, edges_count;
    std::cin >> vertexes_count >> edges_count;

    AdjacencyList<std::size_t> adjacency_list(vertexes_count, std::vector<List>());

    std::size_t max_weight = 0;
    {
        std::size_t u, v, w;
        for (std::size_t i = 0; i != edges_count; ++i) {
            std::cin >> u >> v >> w;

            max_weight = std::max(w, max_weight);
            adjacency_list[u - 1].push_back({v - 1, w});
            adjacency_list[v - 1].push_back({u - 1, w});
        }
    }

    for (std::size_t weight = max_weight; weight != 0; --weight) {
        if (BFS(adjacency_list, weight) == BFS(adjacency_list, max_weight, false)) {
            std::cout << weight << std::endl;
            return EXIT_SUCCESS;
        }
    }

    std::cout << 0 << std::endl;
    return EXIT_SUCCESS;
}