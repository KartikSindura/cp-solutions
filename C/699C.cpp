#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int memo[105][4];
int solve(int i, int n, int last, vector<int> &vec) {
  if (i == n) {
    return 0;
  }

  if (memo[i][last] != -1) {
    return memo[i][last];
  }

  if (vec[i] == 0) {
    // rest day
    memo[i][last] = 1 + solve(i + 1, n, 0, vec);
  } else if (vec[i] == 1) {
    // contest day
    if (last == 1) {
      memo[i][last] = 1 + solve(i + 1, n, 0, vec);
    } else {
      memo[i][last] = solve(i + 1, n, 1, vec);
    }
  } else if (vec[i] == 2) {
    // gym day
    if (last == 2) {
      memo[i][last] = 1 + solve(i + 1, n, 0, vec);
    } else {
      memo[i][last] = solve(i + 1, n, 2, vec);
    }
  } else if (vec[i] == 3) {
    // both
    if (last == 1) {
      memo[i][last] = solve(i + 1, n, 2, vec);
    } else if (last == 2) {
      memo[i][last] = solve(i + 1, n, 1, vec);
    } else {
      memo[i][last] = min(solve(i + 1, n, 1, vec), solve(i + 1, n, 2, vec));
    }
  }
  return memo[i][last];
}

int main() {
  int n;
  cin >> n;
  vector<int> vec;
  while (n--) {
    int a;
    cin >> a;
    vec.push_back(a);
  }
  memset(memo, -1, sizeof memo);
  cout << solve(0, vec.size(), 0, vec);
}

// Think on paper, not on code.
// Read problem statement twice.
// Think pictorially.

// Range overlap check => !(b<c || d<a)
// cout << setprecision(int);
// cout << num;
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
