#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  ll ans = 0;
  ll n, k;
  cin >> n >> k;
  vector<pair<ll, ll>> v;
  for (ll i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    v.push_back({x, y});
  }
  vector<pair<ll, ll>> v1;
  for (auto it : v) {
    v1.push_back({min(2 * it.first, it.second) - min(it.first, it.second),
                  min(it.first, it.second)});
  }
  sort(v1.rbegin(), v1.rend());
  for (ll i = 0; i < v1.size(); i++) {
    if (i < k)
      ans += (v1[i].first + v1[i].second);
    else
      ans += v1[i].second;
  }

  cout << ans;
}

// 1 8
// 3 5
// 2 7
// 1 3
