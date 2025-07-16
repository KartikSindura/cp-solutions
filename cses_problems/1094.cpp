#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  lp(i, n) { cin >> vec[i]; }
  ll moves = 0;
  for (int i = 1; i < vec.size(); i++) {
    if (vec[i] < vec[i - 1]) {
      int diff = abs(vec[i] - vec[i - 1]);
      moves += diff;
      vec[i] += diff;
    }
  }
  cout << moves;
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
