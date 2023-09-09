#include <bits/stdc++.h>

using Matrix = std::vector<std::vector<int>>;

int main() {
    int N, M, Q;
    std::cin >> N >> M >> Q;

    std::vector<std::string> column_names(M);
    for (auto &name : column_names)
        std::cin >> name;

    Matrix matrix(N, std::vector<int>(M, 0));
    for (auto &row : matrix)
        for (auto &row_item : row)
            std::cin >> row_item;

    std::vector<bool> is_closed(N, false);

    int value; char op;
    std::string col_name;
    for (int i = 0; i != Q; ++i) {
        std::cin >> col_name >> op >> value;

        auto column_it = std::find(column_names.begin(), column_names.end(), col_name);
        auto column_index = column_it - column_names.begin();

        if (op == '<') {
            for (int row = 0; row != N; ++row) {
                if (matrix[row][column_index] >= value)
                    is_closed[row] = true;
            }
        } else {
            for (int row = 0; row != N; ++row) {
                if (matrix[row][column_index] <= value)
                    is_closed[row] = true;
            }
        }

        if (std::all_of(is_closed.begin(), is_closed.end(), [](auto item) {
            return item == true;
        })) {
            std::cout << 0 << std::endl;
            return 0;
        }
    }

    int sum = 0;
    for (int row = 0; row != N; ++row) {
        if (!is_closed[row])
            sum += std::accumulate(matrix[row].begin(), matrix[row].end(), 0);
    }

    std::cout << sum << std::endl;

    return EXIT_SUCCESS;
}

// Time complex: O(Q * (M + N + N)) = O(Q * N)