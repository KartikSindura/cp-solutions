#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

bool solve(int n, int ans, vector<int> &nums, int prev) {
  if (i >= n) {
    if (ans == 23) {
      return true;
    }
    return false;
  }
  for (int num = 0; num < 5; num++) {
    if (nums[num] == prev) {
      continue;
    }
    for (int op = 0; op < 3; op++) {
      if (op == 0) {
        ans += nums[num];
        if (solve(n, ans, nums, prev)) {
          return true;
        }
        ans -= nums[num];
      }
      if (op == 1) {
        ans -= nums[num];
        if (solve(n, ans, nums, prev)) {
          return true;
        }
        ans += nums[num];
      }
      if (op == 2) {
        ans *= nums[num];
        if (solve(n, ans, nums, prev)) {
          return true;
        }
        ans /= nums[num];
      }
    }
  }
  return false;
}

int main() {
  while (true) {
    vector<int> nums(5);
    cin >> nums[0] >> nums[1] >> nums[2] >> nums[3] >> nums[4];
    if (nums == vector<int>{0, 0, 0, 0, 0}) {
      break;
    }
    if (solve(4, 0, 0, nums)) {
      cout << "Possible" << endl;
    } else {
      cout << "Impossible" << endl;
    }
  }
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
