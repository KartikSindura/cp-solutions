#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

void solve(vector<int> &arr, int n, int k) {
  for (int i = 1; i < n - k + 2; i++) {
    if (arr[i] != 1) {
      cout << 1 << endl;
      return;
    }
  }
  cout << 2 << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    lp(i, n) { cin >> arr[i]; }
    int total = 0;

    if (n == k) {
      for (int i = 1, count = 1; i < n; i += 2, count++) {
        if (count == arr[i]) {
          total++;
        } else {
          break;
        }
      }
      cout << total + 1 << endl;
    } else {
      solve(arr, n, k);
    }
  }
}

// 0 1 0 1 0

// Think on paper, not on code.
// Read problem statement twice.
// Think pictorially.

// Range overlap check => !(b<c || d<a)
// cout << setprecision(int);
// cout << num;
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// 3 2
// 2 2 1
