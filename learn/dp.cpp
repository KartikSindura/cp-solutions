#include <bits/stdc++.h>
#include <cstring>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

// int mem[3][3] = {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}};
int mem[3][3] = {0};
int grid[3][3] = {{5, 1, 2}, {6, 7, 8}, {1, 4, 9}};

bool valid(int r, int c, int n) { return r >= 0 && c >= 0 && r < n && c < n; }

int maxPathSum_save(int r, int c, int n) {
  cout << r << " " << c << " " << grid[r][c] << endl;
  if (!valid(r, c, n)) {
    return 0;
  }

  if (r == n - 1 && c == n - 1) {
    return grid[r][c];
  }

  if (mem[r][c] != 0) {
    return mem[r][c];
  }

  int path1 = maxPathSum_save(r, c + 1, n);
  int path2 = maxPathSum_save(r + 1, c, n);

  return mem[r][c] = grid[r][c] + max(path1, path2);
}

int main() { cout << maxPathSum_save(0, 0, 3); }

// 512
// 678
// 149

// Think on paper, not on code.
// Read problem statement twice.
// Think pictorially.

// Range overlap check => !(b<c || d<a)
// cout << setprecision(int);
// cout << num;
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
