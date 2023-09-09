#include <iostream>
#include <list>
#include <set>
#include <vector>
 
bool OneData();
 
int main() {
  size_t n;
  std::cin >> n;
  std::vector<bool> answers(n);
  for (size_t i = 0; i < n; ++i) {
    answers[i] = OneData();
  }
  for (size_t i = 0; i < n; ++i) {
    if (answers[i]) {
      std::cout << "YES" << std::endl;
    } else {
      std::cout << "NO" << std::endl;
    }
  }
  return 0;
}
 
bool OneData() {
  size_t n;
  std::cin >> n;
  std::list<int> mas;
  for (size_t i = 0; i < n; ++i) {
    int buffer;
    std::cin >> buffer;
    mas.push_back(buffer);
  }
  mas.unique();
  std::set<int> set;
  for (auto it = mas.begin(); it != mas.end(); ++it) {
    if ((set.find(*it) == set.end()) || (set.empty())) {
      set.insert(*it);
    } else {
      return false;
    }
  }
  return true;
}
