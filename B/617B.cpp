#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  int n;
  cin >> n;
  vector<int> pos;
  lp(i, n) {
    int x;
    cin >> x;
    if (x == 1) {
      pos.push_back(i);
    }
  }

  ll ans = 1;
  if (pos.size() == 0) {
    cout << 0 << endl;
  } else if (pos.size() == 1) {
    cout << 1;
  } else {
    for (int i = 0; i < pos.size() - 1; i++) {
      ans *= pos[i + 1] - pos[i];
    }
    cout << ans << endl;
  }
}

// Think on paper, not on code.
// Read problem statement twice.
// Think pictorially.

// Range overlap check => !(b<c || d<a)
// cout << setprecision(int);
// cout << num;
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
