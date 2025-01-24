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
    vector<int> a, b;
    int n;
    cin >> n;
    lp(i, n) {
      int inp;
      cin >> inp;
      a.push_back(inp);
    }
    lp(i, n) {
      int inp;
      cin >> inp;
      b.push_back(inp);
    }
    lp(i, n - 1) {
      if (a[i] > b[i + 1]) {
        ans += a[i] - b[i + 1];
      }
    }
    ans += a[n - 1];
    cout << ans << endl;
  }
}
