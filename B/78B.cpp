#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lp1(i, n) for (int i = 1; i <= n; i++)

int main() {
  int n;
  cin >> n;
  string colors = "VIBGYOR";
  string gyor = "GYOR";
  string ans = colors;
  if (n > 7) {
    for (int i = 0, count = 0; i < n - 7; i++) {
      if (count == 3) {
        ans += gyor[count];
        count = 0;
      } else {
        ans += gyor[count];
        count++;
      }
    }
    cout << ans;
  } else {
    cout << ans;
  }
}
