#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int dp[105][4];
int solve(int i, int lastDay, int n, vector<int> &tasks) {
  if (i == n) {
    return 0;
  }

  int &ret = dp[i][lastDay];
  if (ret != -1) {
    return ret;
  }

  int ans = 105;
  if (tasks[i] == 0) {
    // rest day
    ans = 1 + solve(i + 1, 0, n, tasks);
  } else if (tasks[i] == 1) {
    // contest
    if (lastDay == 1) {
      ans = 1 + solve(i + 1, 0, n, tasks);
    } else {
      ans = solve(i + 1, 1, n, tasks);
    }
  } else if (tasks[i] == 2) {
    // gym
    if (lastDay == 2) {
      ans = 1 + solve(i + 1, 0, n, tasks);
    } else {
      ans = solve(i + 1, 2, n, tasks);
    }
  } else if (tasks[i] == 3) {
    // both contest and gym
    if (lastDay == 1) {
      ans = solve(i + 1, 2, n, tasks);
    } else if (lastDay == 2) {
      ans = solve(i + 1, 1, n, tasks);
    } else {
      ans = min(solve(i + 1, 2, n, tasks), solve(i + 1, 1, n, tasks));
    }
  }
  return ret = ans;
}

int main() {
  int n;
  vector<int> tasks;
  cin >> n;
  while (n--) {
    int a;
    cin >> a;
    tasks.push_back(a);
  }
  memset(dp, -1, sizeof dp);
  cout << solve(0, 0, tasks.size(), tasks);
}

// Think on paper, not on code.
// Read problem statement twice.
// Think pictorially.

// Range overlap check => !(b<c || d<a)
// cout << setprecision(int);
// cout << num;
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
