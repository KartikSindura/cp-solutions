#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

vector<pair<int, int>> mstEdges;
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

  int find_set(int node) {
    if (node == parent[node])
      return node;
    return parent[node] = find_set(parent[node]);
  }

  void unionByRank(int u, int v) {
    int ulp_u = find_set(u);
    int ulp_v = find_set(v);
    if (ulp_u == ulp_v)
      return;
    if (rank[ulp_u] == rank[ulp_v]) {
      parent[ulp_u] = ulp_v;
    } else if (rank[ulp_v] == rank[ulp_u]) {
      parent[ulp_v] = ulp_u;
    } else {
      parent[ulp_v] = ulp_u;
      rank[ulp_u]++;
    }
  }
};

int kruskal(int n, vector<tuple<int, int, int>> &edges, bool addToMstEdges) {
  DisjointSet ds(n);
  int mstWt = 0;
  mstEdges.clear();
  for (auto &[a, b, w] : edges) {
    if (ds.find_set(a) != ds.find_set(b)) {
      ds.unionByRank(a, b);
      mstWt += w;
      if (addToMstEdges) {
        mstEdges.push_back({a, b});
      }
    }
  }
  return mstWt;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edges(m);
    lp(i, m) {
      int a, b, w;
      cin >> a >> b >> w;
      edges[i] = {a, b, w};
    }

    sort(edges.begin(), edges.end(),
         [](const tuple<int, int, int> &a, const tuple<int, int, int> &b) {
           return get<2>(a) < get<2>(b);
         });

    int minimumMstW = kruskal(n, edges, true);
    int secondminMstW = INT_MAX;
    for (auto &[u, v] : mstEdges) {
      auto copyEdges = edges;
      copyEdges.erase(remove_if(copyEdges.begin(), copyEdges.end(),
                                [&](const tuple<int, int, int> &e) {
                                  return (get<0>(e) == u && get<1>(e) == v) ||
                                         (get<0>(e) == v && get<1>(e) == u);
                                }));
      int newMstW = kruskal(n, copyEdges, false);
      if (newMstW >= minimumMstW) {
        secondminMstW = min(newMstW, secondminMstW);
      }
    }
    cout << minimumMstW << " " << secondminMstW << endl;
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
//
// 2
// 5 8
// 1 3 75
// 3 4 51
// 2 4 19
// 3 2 95
// 2 5 42
// 5 4 31
// 1 2 9
// 3 5 66
// 9 14
// 1 2 4
// 1 8 8
// 2 8 11
// 3 2 8
// 8 9 7
// 8 7 1
// 7 9 6
// 9 3 2
// 3 4 7
// 3 6 4
// 7 6 2
// 4 6 14
// 4 5 9
// 5 6 10
