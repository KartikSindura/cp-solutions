#include <bits/stdc++.h>
#include <queue>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int dp[183][183];
vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};
int n, m;

bool valid(int nx, int ny) { return nx < n && ny < m && nx >= 0 && ny >= 0; }

int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        dp[i][j] = 1e9;
      }
    }

    for (int i = 0; i < n; i++) {
      string x;
      cin >> x;
      for (int j = 0; j < m; j++) {
        grid[i][j] = x[j] - '0';
        if (grid[i][j] == 1) {
          // push location of 1
          q.push({i, j});
          dp[i][j] = 0;
        } else {
          dp[i][j] = -1;
        }
      }
    }
    int level = 0;
    while (!q.empty()) {
      int level_size = q.size();
      for (int i = 0; i < level_size; i++) {
        auto item = q.front();
        int r = item.first;
        int c = item.second;
        q.pop();
        for (int k = 0; k < 4; k++) {
          int nx = dx[k] + r;
          int ny = dy[k] + c;
          if (valid(nx, ny) && dp[nx][ny] == -1) {
            dp[nx][ny] = level + 1;
            q.push({nx, ny});
          }
        }
      }
      level++;
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << dp[i][j] << " ";
      }
      cout << endl;
    }
  }
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
