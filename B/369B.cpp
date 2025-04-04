#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  int n, k, l, r, sa, sk;
  cin >> n >> k >> l >> r >> sa >> sk;
  vector<int> ans(n);
  int rem = sk % k;
  lp(i, k) {
    ans[i] = sk / k + (rem > 0);
    rem--;
  }
  if (n != k) {
    int a = sa - sk;
    int b = n - k;
    rem = a % b;
    for (int i = k; i < n; i++) {
      ans[i] = a / b + (rem > 0);
      rem--;
    }
  }
  for (auto &val : ans) {
    cout << val << " ";
  }
}

// Think on paper, not on code.
// Read problem statement twice.
// Think pictorially.

// Range overlap check => !(b<c || d<a)
// cout << setprecision(int);
// cout << num;
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
