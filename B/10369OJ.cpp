#include <bits/stdc++.h>
#include <iomanip>
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
    int s, n;
    cin >> s >> n;
    vector<pair<int, int>> p(n);
    vector<tuple<float, int, int>> weights;
    lp(i, n) { cin >> p[i].first >> p[i].second; }
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        float d = sqrt(pow(p[i].first - p[j].first, 2) +
                       pow(p[i].second - p[j].second, 2));
        weights.push_back({d, i, j});
      }
    }
    sort(weights.begin(), weights.end(),
         [](const tuple<float, int, int> &a, const tuple<float, int, int> &b) {
           return get<0>(a) < get<0>(b);
         });

    DisjointSet ds(n);
    vector<float> mst;
    for (auto &[w, a, b] : weights) {
      if (ds.findUltimateParent(a) != ds.findUltimateParent(b)) {
        ds.unionByRank(a, b);
        mst.push_back(w);
      }
    }
    sort(mst.rbegin(), mst.rend());
    cout << fixed << setprecision(2) << mst[s - 1] << endl;
  }
  return 0;
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
