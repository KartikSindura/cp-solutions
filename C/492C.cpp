#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#define int long long

using namespace std;

int32_t main() {
  int n, r, avg;

  cin >> n >> r >> avg;

  vector<pair<int, int>> que;

  int sum = 0;

  for (int i = 0; i < n; i++) {
    pair<int, int> p;
    cin >> p.first >> p.second;
    sum += p.first;
    que.push_back(p);
  }

  int req = n * avg;

  sort(que.begin(), que.end(), [](pair<int, int> &a, pair<int, int> &b) {
    if (a.second == b.second) {
      return a.second < b.second;
    }
    return a.second < b.second;
  });

  int count = 0;

  for (int i = 0; i < n; i++) {
    if (sum >= req) {
      break;
    }
    if (que[i].first < r) {
      int dif = r - que[i].first;
      if (dif <= req - sum) {
        count += 1LL * dif * que[i].second;
        sum += dif;
      } else {
        count += 1LL * que[i].second * (req - sum);
        sum += (req - sum);
      }
    }
  }
  cout << count;
}
