#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  ll n;
  cin >> n;
  map<ll, ll> count_x, count_y;
  map<pair<ll, ll>, ll> count_point;
  lp(i, n) {
    ll x, y;
    cin >> x >> y;
    count_x[x]++;
    count_y[y]++;
    count_point[{x, y}]++;
  }
  ll cx = 0;
  for (auto &[u, v] : count_x) {
    if (v > 1) {
      cx += (v * (v - 1)) / 2;
    }
  }
  ll cy = 0;
  for (auto &[u, v] : count_y) {
    if (v > 1) {
      cy += (v * (v - 1)) / 2;
    }
  }
  ll cp = 0;
  for (auto &[u, v] : count_point) {
    if (v > 1) {
      cp += (v * (v - 1)) / 2;
    }
  }
  cout << cx + cy - cp;
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
