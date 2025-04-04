#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> vec(n);
  lp(i, n) { cin >> vec[i].first >> vec[i].second; }
  stable_sort(vec.begin(), vec.end(),
              [](const pair<int, int> a, pair<int, int> b) {
                return a.second > b.second;
              });
  for (auto &[u, v] : vec) {
    cout << u << " " << v << endl;
  }
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
