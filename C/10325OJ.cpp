#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

ll gcd(ll a, ll b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
  ll n;
  int k;
  while (cin >> n >> k) {
    vector<int> vec(k);
    lp(i, k) { cin >> vec[i]; }
    sort(vec.begin(), vec.end());
    int subset_count = 1 << k;
    vector<vector<int>> subsets;

    ll bad = 0;
    for (int i = 1; i < subset_count; i++) {
      ll curr_lcm = 1;
      int subset_size = 0;
      bool overflow = false;
      vector<int> subset;
      for (int j = 0; j < k; j++) {
        if (i & (1 << j)) {
          // bit is set
          subset_size++;
          curr_lcm = lcm(curr_lcm, vec[j]);
          if (curr_lcm > n) {
            overflow = true;
            break;
          }
        }
      }
      if (overflow)
        continue;
      if (subset_size % 2 == 0) {
        bad -= n / curr_lcm;
      } else {
        bad += n / curr_lcm;
      }
    }
    cout << n - bad << endl;
  }
}
// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
