#include <iostream>
#include <map>
#include <vector>
 
std::vector<std::pair<int, int>> OneData();
 
int main() {
  size_t n;
  std::cin >> n;
  std::vector<std::vector<std::pair<int, int>>> all_answer(n);
  for (size_t i = 0; i < n; ++i) {
    all_answer[i] = OneData();
  }
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < all_answer[i].size(); ++j) {
      std::cout << all_answer[i][j].first << " " << all_answer[i][j].second
                << std::endl;
    }
    if (i != n - 1) {
      std::cout << std::endl;
    }
  }
 
  return 0;
}
 
std::vector<std::pair<int, int>> OneData() {
  size_t n;
  std::cin >> n;
  std::map<int, int> data;
  std::vector<std::pair<int, int>> answer(n / 2);
  for (size_t i = 0; i < n; ++i) {
    int buf;
    std::cin >> buf;
    data.insert(std::make_pair(i + 1, buf));
  }
  size_t i = 0;
  for (auto it = data.begin(); it != data.end(); ++i) {
    answer[i].first = (*it).first;
    int buf = (*it).second;
    int delta = 100;
    int key_pair = 0;
 
    for (auto it2 = ++(data.begin()); it2 != data.end(); ++it2) {
      if (abs(buf - (*it2).second) < delta) {
        delta = abs(buf - (*it2).second);
        key_pair = (*it2).first;
      }
    }
    answer[i].second = key_pair;
    data.erase(answer[i].first);
    data.erase(answer[i].second);
    it = data.begin();
  }
  return answer;
}
