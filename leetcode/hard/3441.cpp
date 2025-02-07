#include <bits/stdc++.h>
#include <cmath>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

const int MAXN = 5 * 1e4 + 5;
int dp[MAXN][5][26];

int solve(int i, string &s, int count, char alpha) {

  if (i == s.size()) {
    return count < 3 ? 1e7 : 0;
  }
  int &ret = dp[i][count][alpha];
  if (ret != -1) {
    return ret;
  }

  int ans = 1e7;

  if (count >= 3) {
    // either continue with the same alphabet
    int cost = abs((alpha - 'a') - (s[i] - 'a'));
    ans = min(ans, cost + solve(i + 1, s, count + 1, alpha));
    // or change the alphabet
    for (char a = 'a'; a < 'z'; a++) {
      if (a == alpha) {
        continue;
      }
      int cost = abs((alpha - 'a') - (a - 'a'));
      ans = min(ans, solve(i + 1, s, 1, a));
    }
  } else {
    // continue with the same alphabet
    int cost = abs((alpha - 'a') - (s[i] - 'a'));
    ans = min(ans, cost + solve(i + 1, s, count + 1, alpha));
  }
  return ret = ans;
}

int main() {
  string caption;
  cin >> caption;
  memset(dp, -1, sizeof dp);
  int best_ans = 1e7;
  for (char a = 'a'; a < 'z'; a++) {
    best_ans = min(best_ans, solve(0, caption, 0, a));
  }
  cout << best_ans << endl;
}

// Think on paper, not on code.
// Read problem statement twice.
// Think pictorially.

// Range overlap check => !(b<c || d<a)
// cout << setprecision(int);
// cout << num;
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
