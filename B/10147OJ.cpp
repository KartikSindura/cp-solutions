#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <tuple>
#include <utility>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

class DisjointSet {
  vector<int> rank, parent;

public:
  DisjointSet(int n) {
    rank.resize(n + 1, 0);
    parent.resize(n + 1);

    for (int i = 0; i <= n; i++) {
      parent[i] = i;
    }
  }

  int findUltimateParent(int node) {
    if (node == parent[node])
      return node;
    return parent[node] = findUltimateParent(parent[node]);
  }

  void unionByRank(int u, int v) {
    int ulp_u = findUltimateParent(u);
    int ulp_v = findUltimateParent(v);
    if (ulp_u == ulp_v)
      return;

    if (rank[ulp_u] < rank[ulp_v]) {
      swap(ulp_u, ulp_v);
    }
    parent[ulp_v] = ulp_u;
    if (rank[ulp_u] == rank[ulp_v]) {
      rank[ulp_u]++;
    }
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int, int>> towns(n);
    vector<tuple<int, int, int>> weights;
    lp(i, n) { cin >> towns[i].first >> towns[i].second; }
    int m;
    cin >> m;
    vector<pair<int, int>> built(m);
    lp(i, m) { cin >> built[i].first >> built[i].second; }
    lp(u, n) {
      lp(v, n) {
        if (u == v) {
          continue;
        } else {

          int x1 = towns[u].first;
          int y1 = towns[u].second;
          int x2 = towns[v].first;
          int y2 = towns[v].second;

          int a = (x2 - x1) * (x2 - x1);
          int b = (y2 - y1) * (y2 - y1);
          int d = round(sqrt(a + b));

          weights.push_back({d, u, v});
        }
      }
    }

    DisjointSet ds(n);
    for (auto [u, v] : built) {
      ds.unionByRank(u - 1, v - 1);
    }
    sort(weights.begin(), weights.end(),
         [](const tuple<int, int, int> &a, const tuple<int, int, int> &b) {
           return get<0>(a) < get<0>(b);
         });
    cout << endl;
    for (auto [w, u, v] : weights) {
      if (ds.findUltimateParent(u) != ds.findUltimateParent(v)) {
        ds.unionByRank(u, v);
        cout << u + 1 << " " << v + 1 << endl;
      }
    }
  }
}

// Think on paper, not on code.
// Read problem statement twice.
// Think pictorially.

// Range overlap check => !(b<c || d<a)
// cout << setprecision(int);
// cout << num;
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
// 1
// 9
// 1 5
// 0 0
// 3 2
// 4 5
// 5 1
// 0 4
// 5 2
// 1 2
// 5 3
// 3
// 1 3
// 9 7
// 1 2
// //
