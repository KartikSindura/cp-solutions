#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int n, m;
vector<string> grid;
vector<vector<int>> visited;
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

bool valid(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }

void dfs(int x, int y, char c, int px, int py) {
  visited[x][y] = 1;

  for (int dir = 0; dir < 4; dir++) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (!valid(nx, ny))
      continue;
    if (grid[nx][ny] != c)
      continue;
    if (nx == px && ny == py)
      continue;
    if (visited[nx][ny]) {
      // if (!(nx == px && ny == py)) {
      cout << "Yes" << endl;
      exit(0);
      // }
      // continue;
    }
    dfs(nx, ny, c, x, y);
  }
}

int main() {
  cin >> n >> m;
  grid.resize(n);
  visited.assign(n, vector<int>(m, 0));
  lp(i, n) { cin >> grid[i]; }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!visited[i][j]) {
        dfs(i, j, grid[i][j], -1, -1);
      }
    }
  }

  cout << "No" << endl;
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
