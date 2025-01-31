#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int dp[100005][3];
vector<pair<ll, ll>> trees;
int solve(int i, int lastState) {

  if (i == trees.size()) {
    return 0;
  }

  if (dp[i][lastState] != -1) {
    return dp[i][lastState];
  }

  int x = trees[i].first, h = trees[i].second;

  if (lastState == 0) {
    // stay
    dp[i][lastState] = solve(i + 1, 0);
    if (i == 0 || x - h > trees[i - 1].first) { // try left
      // dp[i][lastState] = 1 + solve(i + 1, 1);
      dp[i][lastState] = max(dp[i][lastState], 1 + solve(i + 1, 1));
    }

    if (i == trees.size() - 1 || x + h < trees[i + 1].first) { // try right
      // dp[i][lastState] = 1 + solve(i + 1, 2);
      dp[i][lastState] = max(dp[i][lastState], 1 + solve(i + 1, 2));
    }

  } else if (lastState == 1) {
    // stay
    dp[i][lastState] = solve(i + 1, 0);
    if (i == 0 || x - h > trees[i - 1].first) { // try left
      // dp[i][lastState] = 1 + solve(i + 1, 1);
      dp[i][lastState] = max(dp[i][lastState], 1 + solve(i + 1, 1));
    }
    if (i == trees.size() - 1 || x + h < trees[i + 1].first) { // try right
      // dp[i][lastState] = 1 + solve(i + 1, 2);
      dp[i][lastState] = max(dp[i][lastState], 1 + solve(i + 1, 2));
    }
  } else if (lastState == 2) {
    // stay
    dp[i][lastState] = solve(i + 1, 0);
    if (i == 0 ||
        x - h > trees[i - 1].first + trees[i - 1].second) { // try left
      // dp[i][lastState] = 1 + solve(i + 1, 1);
      dp[i][lastState] = max(dp[i][lastState], 1 + solve(i + 1, 1));
    }
    if (i == trees.size() - 1 || x + h < trees[i + 1].first) { // try right
      // dp[i][lastState] = 1 + solve(i + 1, 2);
      dp[i][lastState] = max(dp[i][lastState], 1 + solve(i + 1, 2));
    }
  }
  return dp[i][lastState];
}

int main() {
  int n;
  cin >> n;
  trees.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> trees[i].first >> trees[i].second;
  }

  memset(dp, -1, sizeof dp);
  cout << solve(0, 0);
}

// Think on paper, not on code.
// Read problem statement twice.
// Think pictorially.

// Range overlap check => !(b<c || d<a)
// cout << setprecision(int);
// cout << num;
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
