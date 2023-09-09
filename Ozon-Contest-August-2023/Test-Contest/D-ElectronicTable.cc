#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

using Matrix = vector<std::vector<uint16_t>>;
using VectorOfMatrix = vector<Matrix>;

int main() {
    uint16_t count = 0;
    cin >> count;

    uint16_t rows, cols, taps_count = 0;

    VectorOfMatrix matrices(count);

    for (uint16_t i = 0; i != count; ++i) {
        cin >> rows >> cols;
        Matrix matrix(rows, vector<uint16_t>(cols));

        // Read matrix from std input
        for (auto &row : matrix) {
            vector<uint16_t> col(cols);
            for (auto &col_item : col)
                cin >> col_item;
            row = std::move(col);
        }

        // Reading order of columns tap
        cin >> taps_count;
        vector<uint16_t> tapping_cols(taps_count);
        for (auto &col : tapping_cols)
            cin >> col;

        // Sorting matrix by tap column index
        for (auto tap : tapping_cols) {
            std::stable_sort(matrix.begin(), matrix.end(),
                      [&](const auto &row1,const auto &row2) {
                return row1[tap - 1] < row2[tap - 1];
            });
        }

        matrices[i] = std::move(matrix);
    }

    for (const auto &matrix : matrices) {
        for (const auto &row : matrix) {
            for (const auto &col : row) {
                std::cout << col << ' ';
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }

}

/**
*/