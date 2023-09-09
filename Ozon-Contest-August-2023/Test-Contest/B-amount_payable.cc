#include <iostream>
#include <map>
#include <vector>
 
int OneData();
 
int main() {
  size_t n;
  std::cin >> n;
  std::vector<int> data(n);
  for (size_t i = 0; i < n; ++i) {
    data[i] = OneData();
  }
  for (size_t i = 0; i < n; ++i) {
    std::cout << data[i] << std::endl;
  }
  return 0;
}
 
int OneData() {
  size_t n;
  std::cin >> n;
  std::map<int, int> data;
  for (size_t i = 0; i < n; ++i) {
    int buf;
    std::cin >> buf;
    if (data.find(buf) != data.end()) {
      data[buf] += 1;
    } else {
      data.insert(std::make_pair(buf, 1));
    }
  }
  int sum = 0;
  for (const auto& pair : data) {
    sum += (pair.second - (pair.second / 3)) * pair.first;
  }
  return sum;
}
