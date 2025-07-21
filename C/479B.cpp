#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> towers(n);
  vector<pair<int, int>> ans;
  lp(i, n) { cin >> towers[i]; }
  int count = 0;
  for (int i = 0; i < k; i++) {
    auto cmin = min_element(towers.begin(), towers.end());
    auto cmax = max_element(towers.begin(), towers.end());
    if (*cmax == *cmin) {
      break;
    }
    ans.push_back({cmax - towers.begin() + 1, cmin - towers.begin() + 1});
    (*cmin)++;
    (*cmax)--;
    count++;
  }
  int cmin = *min_element(towers.begin(), towers.end());
  int cmax = *max_element(towers.begin(), towers.end());
  cout << cmax - cmin << " " << count << endl;
  for (auto &[u, v] : ans) {
    cout << u << " " << v << endl;
  }
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
