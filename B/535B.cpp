#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  string n;
  cin >> n;
  int digits = n.size();
  int total = 1 << digits;

  for (int i = 0; i < total; ++i) {
    string word;
    for (int j = digits - 1; j >= 0; --j) {
      int bit = ((i >> j) & 1);
      word += bit == 1 ? '7' : '4';
    }
    if (word == n) {
      int before = (1 << digits) - 1;
      cout << before + i;
      return 0;
    }
  }
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
