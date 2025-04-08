#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << " " << 2 << " " << 3 << endl;
  } else if (n == 2) {
    cout << 3 << " " << 4 << " " << 5 << endl;
  } else {
    cout << -1 << endl;
  }
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
