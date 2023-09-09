#include <bits/stdc++.h>

int main() {
    std::ifstream fin("test");
    std::size_t n, m;
    fin >> n >> m;

    std::vector<int> count_new_band(n + 1, 1);
    std::vector<int> current_band_id(n + 1);

    std::iota(current_band_id.begin(), current_band_id.end(), 0);
    int id = current_band_id.back() + 1, x, y, q;

    std::string answer;
    for (std::size_t i = 0; i != m; ++i) {
        fin >> q;
        if (q != 3)
            fin >> x >> y;
        else
            fin >> x;
         if (q == 1) {
             if (current_band_id[x] == current_band_id[y])
                 continue;

             auto current_band_id_x = current_band_id[x],
                  current_band_id_y = current_band_id[y];

             for (std::size_t j = 1; j != current_band_id.size(); ++j) {
                 if (current_band_id[j] == current_band_id_x or current_band_id[j] == current_band_id_y) {
                     current_band_id[j] = id;
                     count_new_band[j]++;
                 }
             }

             id++;
         } else if (q == 2) {
             if (current_band_id[x] == current_band_id[y])
                 answer += "YES\n";
             else
                 answer += "NO\n";
         } else {
             answer += std::to_string(count_new_band[x]) + '\n';
         }
    }

    std::cout << answer << std::endl;

    std::cout << "Band id: " << std::endl;
    int pid = 1;
    for (const auto &item : current_band_id) {
        if (item != 0)
            std::cout << pid++ << ": " << item << " | ";
    }

    std::cout << '\n' << "Count entered new groups: " << std::endl;
    pid = 1;
    for (const auto &item : count_new_band) {
        if (item != 0)
            std::cout << pid++ << ": " << item << " | ";
    }

    return EXIT_SUCCESS;
}