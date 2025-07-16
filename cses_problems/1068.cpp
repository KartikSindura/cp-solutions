#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  ll n;
  cin >> n;
  if (n == 4) {
    cout << "4 2 1";
    return 0;
  } else if (n == 2) {
    cout << "2 1";
    return 0;
  } else if (n == 1) {
    cout << "1";
    return 0;
  }
  while (n != 4 && n != 2 && n != 1) {
    if (n % 2 == 0) {
      cout << n << " ";
      n /= 2;
    } else {
      cout << n << " ";
      n = 3 * n + 1;
    }
  }
  cout << "4 2 1";
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
