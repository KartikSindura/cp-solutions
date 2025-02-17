#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int solve(vector<int> &lab, int n) {
  int ans = n;
  int j = 0;
  for (int i = 0; i < n; i++) {
    while (j < n && lab[j] <= 2 * lab[i]) {
      j++;
    }
    ans = min(ans, i + (n - j));
  }
  return ans;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n;
  cin >> n;
  vector<int> lab(n);
  lp(i, n) { cin >> lab[i]; }
  sort(lab.begin(), lab.end());
  cout << solve(lab, n);
}

// Think on paper, not on code.
// Read problem statement twice.
// Think pictorially.

// Range overlap check => !(b<c || d<a)
// cout << setprecision(int);
// cout << num;
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
