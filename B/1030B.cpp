#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

float area(int x1, int y1, int x2, int y2, int x3, int y3) {
  return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y) {
  float A = area(x1, y1, x2, y2, x3, y3);
  float A1 = area(x, y, x2, y2, x3, y3);
  float A2 = area(x1, y1, x, y, x3, y3);
  float A3 = area(x1, y1, x2, y2, x, y);
  return (A == A1 + A2 + A3);
}

int main() {
  int n, d;
  cin >> n >> d;
  int m;
  cin >> m;

  vector<pair<int, int>> gh(m);
  lp(i, m) { cin >> gh[i].first >> gh[i].second; }

  for (auto &val : gh) {
    if (isInside(0, d, d, 0, n - d, n, val.first, val.second) ||
        isInside(d, 0, n, n - d, n - d, n, val.first, val.second)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
