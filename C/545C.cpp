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

  int currentMax = 0;
  long long lastPosition;

  if (i == 0) {
    lastPosition = -1e10;
  } else {
    if (lastState == 1) { // Previous fell left
      lastPosition = trees[i - 1].first - trees[i - 1].second;
    } else if (lastState == 2) { // Previous fell right
      lastPosition = trees[i - 1].first + trees[i - 1].second;
    } else { // Previous standing
      lastPosition = trees[i - 1].first;
    }
  }

  if (i == 0 || trees[i].first - trees[i].second > lastPosition) {
    // try left
    currentMax = max(currentMax, 1 + solve(i + 1, 1));
  }

  if (i == trees.size() - 1 ||
      trees[i].first + trees[i].second < trees[i + 1].first) {
    // try right
    currentMax = max(currentMax, 1 + solve(i + 1, 2));
  }
  // stay
  currentMax = max(currentMax, solve(i + 1, 0));
  return dp[i][lastState] = currentMax;
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
