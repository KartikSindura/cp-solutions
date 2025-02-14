#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  int n, m;
  cin >> n >> m;
  int ans = 0;
  vector<int> milega(105);
  vector<int> dena(105);
  lp(i, m) {
    int a, b, x;
    cin >> a >> b >> x;
    milega[b] += x;
    dena[a] += x;
  }

  for (int i = 0; i < n + 1; i++) {
    if (milega[i] > dena[i]) {
      ans += milega[i] - dena[i];
    }
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
