#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

bool isOverlap(int a, int b, int c, int d) { return !(b < c || d < a); }

bool hasOverlap(vector<pair<int, int>> lz, vector<pair<int, int>> lx, int i) {
  for (auto &j : lz) {
    for (auto &k : lx) {
      if (isOverlap(j.first, j.second, k.first + i, k.second + i)) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  int p, q, l, r;
  vector<pair<int, int>> lz;
  vector<pair<int, int>> lx;
  int count = 0;
  cin >> p >> q >> l >> r;
  while (p--) {
    int a, b;
    cin >> a >> b;
    lz.push_back({a, b});
  }
  while (q--) {
    int c, d;
    cin >> c >> d;
    lx.push_back({c, d});
  }
  bool flag = false;
  for (int i = l; i < r + 1; i++) {
    count += hasOverlap(lz, lx, i);
  }
  cout << count;
}
