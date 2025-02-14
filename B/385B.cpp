#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  int ans = 0;
  string bear;
  cin >> bear;
  vector<int> starts;
  int x, y = 1;
  for (int i = 0; i < bear.size() + 3; i++) {
    if (bear[i] == 'b' && bear[i + 1] == 'e' && bear[i + 2] == 'a' &&
        bear[i + 3] == 'r') {
      starts.push_back(i + 1);
    }
  }

  for (int i = 0; i < starts.size(); i++) {
    // bearbtxyz
    int x = bear.size() - starts[i] - 2;
    // int y = starts[i];
    // ans += x + 1;
    // if (y > 0) {
    //   ans += y * (x + 1);
    // }
    // if (i > 0) {
    //   ans -= i * (1 + x);
    // }
    // cout << ans << " " << x << " " << y << " " << endl;
    if (i > 0) {
      y = starts[i - 1] + 1;
    }
    y = starts[i] - y + 1;
    ans += x * y;
  }

  cout << ans;
}

// Think on paper, not on code.
// Read problem statement twice.
// Think pictorially.

// Range overlap check => !(b<c || d<a)
// cout << setprecision(int);
// cout << num;
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
