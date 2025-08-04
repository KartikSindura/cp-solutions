#include <bits/stdc++.h>
#include <climits>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

bool safe(unordered_map<string, vector<pair<int, int>>> &items, int b,
          int minq) {
  int total = 0;
  for (auto &[type, components] : items) {
    ll cheapest = LLONG_MAX;
    for (auto &val : components) {
      if (val.second >= minq) {
        cheapest = min(cheapest, (ll)val.first);
      }
    }
    if (cheapest == LLONG_MAX) {
      return false;
    }
    total += cheapest;
    if (total > b) {
      return false;
    }
  }
  return true;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    int b;
    cin >> n >> b;
    unordered_map<string, vector<pair<int, int>>> items;
    string last;
    int maxq = 0;
    lp(i, n) {
      string type, name;
      int p;
      int q;
      cin >> type >> name >> p >> q;
      items[type].emplace_back(p, q);
      maxq = max(maxq, q);
    }
    int low = 0;
    int high = maxq;
    int ans = -1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (safe(items, b, mid)) {
        ans = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
