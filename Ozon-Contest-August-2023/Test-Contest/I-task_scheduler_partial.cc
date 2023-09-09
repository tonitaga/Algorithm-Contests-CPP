#include <iostream>
#include <map>
#include <vector>
 
long long SumProc(std::multimap<long long, long long> &processors);
 
int main() {
  size_t n, m;
  std::cin >> n >> m;
  std::multimap<long long, long long> processors;
  std::vector<std::pair<long long, long long>> tasks(m);
  for (size_t i = 0; i < n; ++i) {
    long long buffer = 0;
    std::cin >> buffer;
    processors.insert(std::make_pair(buffer, 0));
  }
  for (size_t i = 0; i < m; ++i) {
    std::cin >> tasks[i].first;
    std::cin >> tasks[i].second;
  }
  long long sum = 0;
  for (size_t i = 0; i < m; ++i) {
    if (i != 0) {
      long long delta = tasks[i].first - tasks[i - 1].first;
      for (auto it = processors.begin(); it != processors.end(); ++it) {
        if ((*it).second != 0) {
          (*it).second -= delta;
          if ((*it).second < 0) {
            (*it).second = 0;
          }
        }
      }
    }
    for (auto it = processors.begin(); it != processors.end(); ++it) {
      if ((*it).second == 0) {
        (*it).second = tasks[i].second;
        sum += tasks[i].second * (*it).first;
        break;
      }
    }
  }
  std::cout << sum << std::endl;
  return 0;
}
 
long long SumProc(std::multimap<long long, long long> &processors) {
  long long sum = 0;
  for (auto it = processors.begin(); it != processors.end(); ++it) {
    sum += (*it).second;
  }
  return sum;
}
