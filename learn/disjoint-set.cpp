#include <bits/stdc++.h>
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

// class DisjointSet {
//   vector<int> rank, parent, size;
//
// public:
//   DisjointSet(int n) {
//     rank.resize(n + 1, 0);
//     parent.resize(n + 1);
//     size.resize(n + 1, 1);
//
//     for (int i = 0; i <= n; i++) {
//       parent[i] = i;
//     }
//   }
//
//   int findUltimateParent(int node) {
//     if (node == parent[node])
//       return node;
//     return parent[node] = findUltimateParent(parent[node]);
//   }
//
//   void unionByRank(int u, int v) {
//     int ulp_u = findUltimateParent(u);
//     int ulp_v = findUltimateParent(v);
//     if (ulp_u == ulp_v)
//       return;
//
//     if (rank[ulp_u] < rank[ulp_v]) {
//       parent[ulp_u] = ulp_v;
//     } else if (rank[ulp_u] > rank[ulp_v]) {
//       parent[ulp_v] = ulp_u;
//     } else { // If ranks are equal, choose one as the root and increment its
//              // rank
//       parent[ulp_v] = ulp_u;
//       rank[ulp_u]++;
//     }
//   }
//
//   void unionBySize(int u, int v) {
//     int ulp_u = findUltimateParent(u);
//     int ulp_v = findUltimateParent(v);
//     if (ulp_u == ulp_v)
//       return;
//
//     if (size[ulp_u] < size[ulp_v]) {
//       swap(ulp_u, ulp_v);
//     }
//     parent[ulp_v] = ulp_u;
//     size[ulp_u] += size[ulp_v];
//   }
// };
// class DisjointSet {
//   vector<int> rank, parent;
//
// public:
//   DisjointSet(int n) {
//     rank.resize(n + 1, 0);
//     parent.resize(n + 1);
//
//     for (int i = 0; i <= n; i++) {
//       parent[i] = i;
//     }
//   }
//
//   int findUltimateParent(int node) {
//     if (node == parent[node])
//       return node;
//     return parent[node] = findUltimateParent(parent[node]);
//   }
//
//   void unionByRank(int u, int v) {
//     int ulp_u = findUltimateParent(u);
//     int ulp_v = findUltimateParent(v);
//     if (ulp_u == ulp_v)
//       return;
//     if (rank[ulp_u] == rank[ulp_v]) {
//       parent[ulp_u] = ulp_v;
//     } else if (rank[ulp_v] == rank[ulp_u]) {
//       parent[ulp_v] = ulp_u;
//     } else {
//       parent[ulp_v] = ulp_u;
//       rank[ulp_u]++;
//     }
//   }
// };

// Think on paper, not on code.
// Read problem statement twice.
// Think pictorially.

// Range overlap check => !(b<c || d<a)
// cout << setprecision(int);
// cout << num;
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
