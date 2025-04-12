#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

typedef long long ll;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<pair<long long, long long>> vpll;
typedef vector<pair<int, int>> vpii;

int main() {
  int n;
  ll d;
  cin >> n >> d;
  vpll friends(n);
  lp(i, n) { cin >> friends[i].first >> friends[i].second; }
  if (friends.size() == 1) {
    cout << friends[0].second;
    return 0;
  }
  sort(friends.begin(), friends.end(),
       [](const pair<ll, ll> &a, const pair<ll, ll> &b) {
         return a.first < b.first;
       });
  ll ans = 0;
  ll fans = 0;
  for (int i = 0, j = 0; j < n; j++) {
    fans += friends[j].second;
    while (friends[j].first - friends[i].first >= d) {
      fans -= friends[i].second;
      i++;
    }
    ans = max(fans, ans);
  }
  cout << ans << endl;
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
