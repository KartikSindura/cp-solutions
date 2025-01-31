#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

// color: white = 0, black = 1

int dp[1005][1005][2];
int solve(int i, int lastColor, int count, vector<string> &grid,
          vector<int> &white_count, int x, int y) {
  int n = grid.size();
  int m = grid[0].size();

  if (i >= m) {
    return count < x ? 1e9 : 0;
  }

  if (dp[i][count][lastColor] != -1) {
    return dp[i][count][lastColor];
  }

  int ans = 1e9;

  / int n, m, x, y;
  cin >> n >> m >> x >> y;
  vector<string> grid(n);
  vector<int> white_count(m, 0);
  lp(i, n) { cin >> grid[i]; }
  lp(i, m) {
    lp(j, n) { white_count[i] += (grid[j][i] == '.'); }
  }

  memset(dp, -1, sizeof dp);
  cout << min(solve(0, 1, 0, grid, white_count, x, y),
              solve(0, 0, 0, grid, white_count, x, y));
}

// Think on paper, not on code.
// Read problem statement twice.
// Think pictorially.

// Range overlap check => !(b<c || d<a)
// cout << setprecision(int);
// cout << num;
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
