#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    int one_count = 0;
    lp(i, n) {
      cin >> v[i];
      if (v[i] == 1)
        one_count++;
    }
    if (one_count >= n) {
      cout << "YES" << endl;
      continue;
    }
    bool found = false;
    for (int i = 0; i < n - 1; i++) {
      if (v[i] == 0 && v[i + 1] == 0) {
        cout << "YES" << endl;
        found = true;
        break;
      }
    }
    if (!found) {
      cout << "NO" << endl;
    }
  }
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
