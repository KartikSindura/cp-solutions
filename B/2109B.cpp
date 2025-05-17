#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

ll findans(ll a, ll b) { return ceil(log2(a)) + ceil(log2(b)); }

int turns(ll n, ll m, ll a, ll b) {
  ll row = min(a, n - a + 1);
  ll col = min(b, m - b + 1);
  ll x = findans(n, col);
  ll y = findans(m, row);
  return min(x, y) + 1;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    ll n, m, a, b;
    cin >> n >> m >> a >> b;
    cout << turns(n, m, a, b) << endl;
  }
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
