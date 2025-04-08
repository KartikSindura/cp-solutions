#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  string a, b;
  cin >> a >> b;
  int n = a.size();
  int m = b.size();
  int len = m - n + 1;

  vector<int> prefix(m + 1);
  for (int i = 0; i < m; i++) {
    prefix[i + 1] = prefix[i] + (b[i] == '1');
  }
  ll total = 0;
  for (int i = 0; i < n; i++) {
    int l = i;
    int r = i + len - 1;
    int ones = prefix[r + 1] - prefix[l];
    int total_pos = r - l + 1;

    if (a[i] == '0') {
      total += ones;
    } else {
      total += total_pos - ones;
    }
  }
  cout << total << endl;
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
