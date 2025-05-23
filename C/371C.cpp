#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  string burger;
  cin >> burger;
  int nb, ns, nc, pb, ps, pc;
  cin >> nb >> ns >> nc >> pb >> ps >> pc;
  ll money;
  cin >> money;
  ll ans = 0;

  int b = 0, s = 0, c = 0;
  for (auto &val : burger) {
    if (val == 'B') {
      b++;
    } else if (val == 'S') {
      s++;
    } else {
      c++;
    }
  }

  auto can_make = [&](ll burgers) {
    ll costb = max(0LL, burgers * b - nb);
    ll costs = max(0LL, burgers * s - ns);
    ll costc = max(0LL, burgers * c - nc);
    return (costb * pb + costs * ps + costc * pc) <= money;
  };

  ll low = 0, high = 1e13;
  while (low <= high) {
    ll mid = (low + high) / 2;
    if (can_make(mid)) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  cout << ans << endl;
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
