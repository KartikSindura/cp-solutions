#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

// void PLAY() {
// #ifndef ONLINE_JUDGE
//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);
// #endif
//   cout << fixed << setprecision(4);
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   cout.tie(0);
// }

vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

bool isValid(int x, int n) { return (x >= 0 && x < n); }

int fix(int y, int m) {
  if (y < 0)
    return m - 1;
  if (y >= m)
    return 0;
  return y;
}

void dfs(vector<string> &grid, int x, int y, int m, int n, int &size,
         vector<vector<int>> &visited, char land) {
  visited[x][y] = 1;
  size++;
  lp(i, 4) {
    int nx = x + dx[i];
    int ny = fix(y + dy[i], m);
    if (isValid(nx, n) && !visited[nx][ny] && grid[nx][ny] == land) {
      dfs(grid, nx, ny, m, n, size, visited, land);
    }
  }
}

int main() {
  // PLAY();
  int n, m;
  while (cin >> n >> m) {
    vector<string> grid(m);
    lp(i, n) { cin >> grid[i]; }

    int x, y;
    cin >> x >> y;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    char land = grid[x][y];

    int own_continent_size = 0;
    dfs(grid, x, y, m, n, own_continent_size, visited, land);

    int max_continent = 0;
    lp(i, n) {
      lp(j, m) {
        if (grid[i][j] == land && !visited[i][j]) {
          int size = 0;
          dfs(grid, i, j, m, n, size, visited, land);
          max_continent = max(max_continent, size);
        }
      }
    }
    cout << max_continent << endl;
  }
  return 0;
}

// Think on paper, not on code.
// Read problem statement twice.
// Think pictorially.

// Range overlap check => !(b<c || d<a)
// cout << setprecision(int);
// cout << num;
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
