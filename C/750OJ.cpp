#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

vector<vector<int>> ans;

bool safe(int row, int col, vector<vector<int>> &board, vector<int> &diag1,
          vector<int> &diag2, vector<int> &cols) {
  return !cols[col] && !diag1[row + col] && !diag2[row - col + 7];
}

void solve(int row, int x, int y, vector<vector<int>> &board,
           vector<int> &diag1, vector<int> &diag2, vector<int> &cols) {
  if (row == 8) {
    vector<int> ansa(8, 0);
    for (int r = 0; r < 8; r++) {
      for (int c = 0; c < 8; c++) {
        if (board[r][c] == 1) {
          ansa[c] = r;
        }
      }
    }
    ans.push_back(ansa);
    return;
  }

  if (row == x) {
    solve(row + 1, x, y, board, diag1, diag2, cols);
    return;
  }

  for (int col = 0; col < 8; col++) {
    if (safe(row, col, board, diag1, diag2, cols)) {
      board[row][col] = 1;
      cols[col] = diag1[row + col] = diag2[row - col + 7] = 1;
      solve(row + 1, x, y, board, diag1, diag2, cols);
      board[row][col] = 0;
      cols[col] = diag1[row + col] = diag2[row - col + 7] = 0;
    }
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    ans.clear();
    vector<vector<int>> board(8, vector<int>(8, 0));
    vector<int> cols(8, 0), diag1(15, 0), diag2(15, 0);
    cols[y] = 1;
    diag1[x + y] = 1;
    diag2[x - y + 7] = 1;
    board[x][y] = 1;
    solve(0, x, y, board, diag1, diag2, cols);
    cout << "SOLN\t" << "COLUMN" << endl;
    cout << "#" << "\t1 2 3 4 5 6 7 8" << endl << endl;
    for (int i = 0; i < ans.size(); i++) {
      cout << i + 1 << "\t";
      for (int j = 0; j < 8; j++) {
        cout << ans[i][j] + 1 << " ";
      }
      cout << endl;
    }
  }
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
