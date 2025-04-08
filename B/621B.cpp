#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  int n;
  cin >> n;
  ll total = 0;
  map<int, int> pm;
  map<int, int> nm;
  lp(i, n) {
    int x, y;
    cin >> x >> y;
    pm[x + y]++;
    nm[x - y]++;
  }
  for (auto &[d, count] : pm) {
    total += (count * (count - 1)) / 2;
  }

  for (auto &[d, count] : nm) {
    total += (count * (count - 1)) / 2;
  }
  cout << total << endl;
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
// visited.assign(n, vector<int>(m, 0));
