#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int limit, m;
  cin >> limit >> m;
  vector<pair<int, int>> vec;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    vec.push_back({a, b});
  }
  int count = 0, capacity = limit;
  while (capacity > 0) {
    int flag = -1, max = 0, max_frnd = 0;

    for (int i = 0; i < vec.size(); i++) {
      if (max < vec[i].second) {
        max = vec[i].second;
        max_frnd = vec[i].first;
        flag = i;
      }
    }

    if (flag == -1) {
      break;
    }

    if (max_frnd <= capacity) {
      count += max * max_frnd;
      vec[flag].first = 0;
      vec[flag].second = 0;
      capacity -= max_frnd;
    } else {
      count += max * capacity;
      vec[flag].first = 0;
      vec[flag].second = 0;
      capacity = 0;
    }
  }
  cout << count;
}
