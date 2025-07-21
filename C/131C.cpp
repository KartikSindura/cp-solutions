#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

ll dp[31];
const int MAX = 61;
ll c[MAX][MAX];

void pre() {
  for (int n = 0; n < MAX; n++) {
    c[n][n] = c[n][0] = 1;
    for (int r = 1; r < 31; r++) {
      c[n][r] = c[n - 1][r - 1] + c[n - 1][r];
    }
  }
}

ll fact(ll num) {
  if (num == 1 || num == 0) {
    return 1;
  }
  if (dp[num] != -1) {
    return dp[num];
  }
  return dp[num] = num * fact(num - 1);
}

int main() {
  int n, m, t;
  cin >> n >> m >> t;
  pre();
  memset(dp, -1, sizeof(dp));
  ll ans = 0;
  for (ll b = 4; b <= n; b++) {
    int g = t - b;
    if (g <= m && g > 0) {
      // cout << b << " " << g << endl;
      ans += c[n][b] * c[m][g];
    }
  }
  cout << ans;
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
