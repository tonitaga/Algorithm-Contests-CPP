#include <bits/stdc++.h>

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &rhs) {
    for (const auto &item : rhs)
        std::cout << item << ' ';
    return out;
}

void CalculateCombinationHelp(const std::vector<int> &a, std::vector<std::vector<int>> &all, std::size_t sum, std::size_t current_sum, std::size_t start, std::vector<int> &answer) {
    if (current_sum == sum) {
        all.push_back(answer);
        return;
    }

    int prev = -1;
    for (std::size_t i = start; i != a.size(); ++i) {
        if (prev != a[i]) {
            if (current_sum + a[i] > sum)
                break;
            answer.push_back(a[i]);
            CalculateCombinationHelp(a, all, sum, current_sum + a[i], i + 1, answer);
            answer.erase(answer.end() - 1);
            prev = a[i];
        }
    }
}

std::vector<int> CalculateCombination(const std::vector<int> &a, std::size_t sum) {
    std::vector<int> answer;
    std::vector<std::vector<int>> all_answers;
    CalculateCombinationHelp(a, all_answers, sum, 0, 0, answer);

    if (all_answers.empty())
        return {};
    return all_answers[0];
}


int main() {
    std::size_t n, m;
    std::cin >> n >> m;

    std::vector<int> a;
    a.reserve(m * 2);

    for (std::size_t i = 0; i != m; ++i) {
        int item;

        std::cin >> item;
        a.push_back(item);
        a.push_back(item);
    }

    std::sort(a.begin(), a.end());

    auto combination = CalculateCombination(a, n);

    if (combination.empty())
        std::cout << -1 << std::endl;
    else
        std::cout << combination.size() << std::endl << combination << std::endl;

    return EXIT_SUCCESS;
}
