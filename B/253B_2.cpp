#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int bs(vector<int> &lab, int n, int i, int low, int high) {
  int smallest = lab[i];
  int ans = -1;

  while (low <= high) {
    int mid = (low + high) / 2;

    if (lab[mid] <= 2 * smallest) {
      low = mid + 1;
      ans = mid;
    } else {
      high = mid - 1;
    }
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
  int ans = n;
  int prev_res = 0;

  for (int i = 0; i < n; i++) {
    int res = bs(lab, n, i, prev_res, n - 1);
    prev_res = res;
    if (res == -1) {
      continue;
    } else {
      ans = min(ans, i + n - res - 1);
    }
  }
  cout << ans;
}

// Think on paper, not on code.
// Read problem statement twice.
// Think pictorially.

// Range overlap check => !(b<c || d<a)
// cout << setprecision(int);
// cout << num;
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
