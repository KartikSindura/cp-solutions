#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  int a;
  ll x, y;
  cin >> a >> x >> y;
  int ylvl;
  int ans = -1;

  if (y % a == 0) {
    ans = -1;
  } else {
    ylvl = (y / a) + 1;
    if (ylvl > 2) {
      // could be either of the 2 or no
      if (ylvl % 2 != 0) {
        // its 2
        if (x > 0 && x < a) {
          // ans = ylvl + 1;
          ans = ylvl + ((ylvl - 1) / 2);
        } else if (x < 0 && x > -a) {
          ans = ylvl - 1 + ((ylvl - 1) / 2);
        } else {
          ans = -1;
        }
      } else {
        if (x < a / 2.0 && x > -a / 2.0) {
          ans = ylvl + ((ylvl / 2) - 1);
        } else {
          ans = -1;
        }
      }
    } else {
      // will only be 1 or 2 or no
      if (x < a / 2.0 && x > -a / 2.0) {
        ans = ylvl;
      } else {
        ans = -1;
      }
    }
  }
  cout << ans << endl;
}

// Think on paper, not on code.
// Read problem statement twice.
// Think pictorially.

// Range overlap check => !(b<c || d<a)
// cout << setprecision(int);
// cout << num;
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
