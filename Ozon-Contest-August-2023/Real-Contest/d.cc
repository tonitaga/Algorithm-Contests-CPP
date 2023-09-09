#include <iostream>
#include <vector>
#include <algorithm>

using CharMatrix = std::vector<std::vector<char>>;

std::istream &operator>>(std::istream &in, CharMatrix &matrix) {
    for (auto &row : matrix) {
        std::vector<char> r(row.size());

        for (auto &item : r)
            in >> item;

        row = std::move(r);
    }
    return in;
}


std::ostream &operator<<(std::ostream &out, const CharMatrix &matrix) {
    for (auto &row : matrix) {
        for (auto &col_item : row)
            out << col_item;
        out << '\n';
    }
    return out;
}

int main() {
    std::size_t tests_count;
    std::cin >> tests_count;

    std::vector<CharMatrix> matrices(tests_count);

    std::size_t mountains_count, rows, cols;
    for (std::size_t i = 0; i != tests_count; ++i) {
        std::cin >> mountains_count >> rows >> cols;
        CharMatrix result_mountain(rows, std::vector<char>(cols, '.'));

        std::vector<CharMatrix> test_matrices(mountains_count, CharMatrix(rows, std::vector<char>(cols)));
        for (std::size_t j = 0; j != mountains_count; ++j) {
            std::cin >> test_matrices[j];
        }

        std::reverse(test_matrices.begin(), test_matrices.end());
        if (test_matrices.size() == 1) {
            result_mountain = std::move(test_matrices[0]);
        } else {
            for (const auto &matrix : test_matrices) {
                for (std::size_t row = 0; row != rows; ++row) {
                    for (std::size_t col = 0; col != cols; ++col) {
                        if (matrix[row][col] != '.')
                            result_mountain[row][col] = matrix[row][col];
                    }
                }
            }
        }

        matrices[i] = std::move(result_mountain);
    }

    for (const auto &matrix : matrices)
        std::cout << matrix << std::endl;
    return 0;
}
