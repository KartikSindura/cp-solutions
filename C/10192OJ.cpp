#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int dp[101][101];
int solve(string &mother, string &father, int i, int j) {
  if (i == mother.size() || j == father.size()) {
    return 0;
  }
  if (dp[i][j] != -1) {
    return dp[i][j];
  }
  if (mother[i] == father[j]) {
    return dp[i][j] = solve(mother, father, i + 1, j + 1) + 1;
  }
  int choice1 = solve(mother, father, i + 1, j);
  int choice2 = solve(mother, father, i, j + 1);
  return dp[i][j] = max(choice1, choice2);
}

int main() {
  string mother;
  int casenum = 0;
  while (getline(cin, mother)) {
    casenum++;
    if (mother == "#") {
      break;
    }
    string father;
    getline(cin, father);
    memset(dp, -1, sizeof dp);
    cout << "Case #" << casenum << ": you can visit at most "
         << solve(mother, father, 0, 0) << " cities." << endl;
  }
  return 0;
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
