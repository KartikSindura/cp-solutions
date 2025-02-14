#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int memo[105][105];
int facts[1000005];

int check(int i, int j) {
  if (memo[i][j] != -1) {
    return memo[i][j];
  }
  return memo[i][j] = memo[j][i] = i * j;
}

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  memset(memo, -1, sizeof memo);
  memset(facts, -1, sizeof facts);

  ll ans = 0;
  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= b; j++) {
      for (int k = 1; k <= c; k++) {
        int total = check(i, j) * k;
        if (facts[total] != -1) {
          ans += facts[total];
        } else {
          int count = 0;
          for (int d = 1; d * d <= total; ++d) { // Optimize divisor count
            if (total % d == 0) {
              count += (d * d == total) ? 1 : 2;
            }
          }
          facts[total] = count;
          ans += count;
        }
      }
    }
  }
  cout << ans % 1073741824;
}
// Think on paper, not on code.
// Read problem statement twice.
// Think pictorially.

// Range overlap check => !(b<c || d<a)
// cout << setprecision(int);
// cout << num;
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
