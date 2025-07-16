#include <bits/stdc++.h>
#include <numeric>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }

int lcm(int a, int b) { return a * b / gcd(a, b); }

int main() {
  int n, t;
  while (cin >> n >> t) {
    if (n == 0 && t == 0) {
      break;
    }
    vector<int> coins(n);
    lp(i, n) { cin >> coins[i]; }
    vector<int> tables(t);
    lp(i, t) { cin >> tables[i]; }

    for (int val = 0; val < tables.size(); val++) {
      int res1 = 0, res2 = INT_MAX;
      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          for (int k = j + 1; k < n; k++) {
            for (int l = k + 1; l < n; l++) {
              int lcms = lcm(coins[i], coins[j]);
              lcms = lcm(lcms, coins[k]);
              lcms = lcm(lcms, coins[l]);
              int a1 = (tables[val] / lcms) * lcms;
              int a2 = a1;
              if (a2 < tables[val]) {
                a2 += lcms;
              }
              res1 = max(a1, res1);
              res2 = min(a2, res2);
            }
          }
        }
      }
      cout << res1 << " " << res2 << endl;
    }
  }
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
