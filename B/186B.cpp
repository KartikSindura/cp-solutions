#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  int n, t1, t2;
  double k;
  vector<pair<double, int>> vec;
  cin >> n >> t1 >> t2 >> k;
  double perc = 1.0 - (k / 100.0);
  lp(i, n) {
    int a, b;
    cin >> a >> b;
    double height = max(a * t1 * perc + b * t2, b * t1 * perc + a * t2);
    vec.push_back({height, i + 1});
  }
  auto comp = [](pair<double, int> a, pair<double, int> b) {
    if (a.first != b.first) {
      return a.first > b.first;
    } else {
      return a.second < b.second;
    }
  };

  sort(vec.begin(), vec.end(), comp);
  for (auto &v : vec) {
    cout << v.second << " " << fixed << setprecision(2) << v.first << endl;
  }
}

// Think on paper, not on code.
// Read problem statement twice.
// Think pictorially.

// Range overlap check => !(b<c || d<a)
// cout << setprecision(int);
// cout << num;
// Look for monotonic behaviour -> binary search
