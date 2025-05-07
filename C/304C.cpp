#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  int n;
  cin >> n;

  if (n % 2 == 0) {
    cout << -1;
    return 0;
  }

  lp(i, n) {
    if (i == n - 1) {
      cout << i;
    } else {
      cout << i << " ";
    }
  }
  cout << endl;
  lp(i, n) {
    if (i == n - 1) {
      cout << i;
    } else {
      cout << i << " ";
    }
  }
  cout << endl;
  lp(i, n) {
    if (i == n - 1) {
      cout << (i + i) % n;
    } else {
      cout << (i + i) % n << " ";
    }
  }
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
