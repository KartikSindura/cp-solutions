#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

// ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

int main() {
  int a, b;
  cin >> a >> b;
  ll g = gcd(a, b);
  cout << "g: " << g << endl;
  ll d = b / g;
  cout << "d: " << d << endl;
  ll m = a / g;
  cout << "m: " << m << endl;
  if (d > m) {
    d--;
  } else {
    m--;
  }
  // cout << d << m << endl;
  if (d < m) {
    cout << "Masha" << endl;
  } else if (d > m) {
    cout << "Dasha" << endl;
  } else {
    cout << "Equal" << endl;
  }
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
