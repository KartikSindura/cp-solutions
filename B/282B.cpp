#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

bool mini(int a, int g) { return a < g; }

int main() {
  int n;
  cin >> n;
  int sa = 0, sg = 0;
  string ans = "";

  while (n--) {
    int a, g;
    cin >> a >> g;
    int diff_a = abs((sa + a) - sg);
    int diff_g = abs(sa - (sg + g));
    if (diff_a <= 500) {
      sa += a;
      ans += 'A';
    } else if (diff_g <= 500) {
      sg += g;
      ans += 'G';
    } else {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans << endl;
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
