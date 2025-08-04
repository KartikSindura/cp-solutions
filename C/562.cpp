#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int dp[101][25000];

int solve(vector<int> &coins, int i, int total, int right) {
  if (i == coins.size()) {
    int left = total - right;
    return abs(left - right);
  }
  if (dp[i][right] != -1) {
    return dp[i][right];
  }
  int ch1 = solve(coins, i + 1, total, right + coins[i]);
  int ch2 = solve(coins, i + 1, total, right);
  return dp[i][right] = min(ch1, ch2);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    memset(dp, -1, sizeof dp);
    vector<int> coins(n);
    int total = 0;
    lp(i, n) {
      cin >> coins[i];
      total += coins[i];
    }
    cout << solve(coins, 0, total, 0) << endl;
  }
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
