#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

class Solution {
public:
  vector<vector<vector<int>>> dp;
  int n;
  ll mod = 1e9 + 7;
  int offset = 1000;
  int getscore(char bob, char alice) {
    if ((bob == 'F' && alice == 'W') || (bob == 'W' && alice == 'E') ||
        (bob == 'E' && alice == 'F')) {
      return 1;
    } else if (bob == alice) {
      return 0;
    } else
      return -1;
  }
  int solve(int i, int last, int score, string &s) {
    if (i >= n) {
      if (score > 0) {
        return 1;
      } else {
        return 0;
      }
    }
    if (dp[i][last][score + offset] != -1) {
      return dp[i][last][score + offset];
    }
    vector<char> moves = {'F', 'W', 'E'};
    int r = 0;
    for (char move : moves) {
      int id = 0;
      if (move == 'F') {
        id = 1;
      } else if (move == 'W') {
        id = 2;
      } else if (move == 'E') {
        id = 3;
      }

      if (last == id) {
        continue;
      }
      int current_score = getscore(s[i], move);
      r = (r + solve(i + 1, id, score + current_score, s)) % mod;
    }
    return dp[i][last][score + offset] = r;
  }

  int countWinningSequences(string s) {
    n = s.size();
    // memset(dp, -1, sizeof(dp));
    dp = vector<vector<vector<int>>>(
        n + 1, vector<vector<int>>(4, vector<int>(2001, -1)));
    return solve(0, 0, 0, s);
  }
};
int main() {
  Solution sol;
  string s = "EEFWEWWFFFWEEWEFFEEEFEFEEFWFEWEFEWWWFFEEEFFFE"; // example input
  cout << sol.countWinningSequences(s) << endl;
  return 0;
}
// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
