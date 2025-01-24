#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  int t;
  cin >> t;
  lp(i, t) {
    int ans = 0;
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int total = a + b + c;
    ans += n / (total);
    int rem = n % total;
    ans *= 3;
    if (rem == 0) {
      cout << ans << endl;
    } else {
      if (rem <= a) {
        ans += 1;
      } else if (rem <= a + b) {
        ans += 2;
      } else if (rem <= a + b + c) {
        ans += 3;
      }

      cout << ans << endl;
    }
  }
}
