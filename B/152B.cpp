#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool onField(ll x, ll y, ll n, ll m) {
  return (x > 0 && x <= n && y > 0 && y <= m);
}

int main() {
  ll n, m, xc, yc, k, moves = 0;
  cin >> n >> m >> xc >> yc >> k;

  while (k--) {
    ll dx, dy;
    cin >> dx >> dy;

    ll maxSteps = 0;
    ll low = 0, high = 1e9;

    while (low <= high) {
      ll mid = (low + high) / 2;
      if (onField(xc + mid * dx, yc + mid * dy, n, m)) {
        maxSteps = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    xc += maxSteps * dx;
    yc += maxSteps * dy;
    moves += maxSteps;
  }

  cout << moves << endl;
  return 0;
}
