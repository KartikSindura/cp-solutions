#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

map<pair<int, int>, int> mp;
ll solve(ll a, ll b) {
  if (a == b) {
    return 0;
  }

  if (a == 0 || b == 0) {
    return INT_MAX;
  }

  if (mp.find({a, b}) != mp.end()) {
    return mp[{a, b}];
  }

  ll dp = INT_MAX;
  if (a % 2 == 0)
    dp = min(dp, 1 + solve(a / 2, b));
  if (b % 2 == 0)
    dp = min(dp, 1 + solve(a, b / 2));
  if (a % 3 == 0)
    dp = min(dp, 1 + solve(a / 3, b));
  if (b % 3 == 0)
    dp = min(dp, 1 + solve(a, b / 3));
  if (a % 5 == 0)
    dp = min(dp, 1 + solve(a / 5, b));
  if (b % 5 == 0)
    dp = min(dp, 1 + solve(a, b / 5));
  return mp[{a, b}] = dp;
}

int main() {
  ll a, b;
  cin >> a >> b;

  if (a == b) {
    cout << 0;
    return 0;
  }
  ll ans = solve(a, b);
  if (ans == INT_MAX) {
    cout << -1 << endl;
    return 0;
  }

  cout << ans;
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
