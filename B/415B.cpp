#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  int n;
  cin >> n;
  ll a, b;
  cin >> a >> b;
  vector<ll> tokens(n);
  vector<ll> ans(n);
  lp(i, n) { cin >> tokens[i]; }
  for (int i = 0; i < n; i++) {
    if (i)
      cout << " ";
    cout << ((tokens[i] * a) % b) / a;
  }
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
