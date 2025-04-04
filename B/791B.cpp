#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

void dfs(int start, set<int> &visited, vector<vector<int>> &adj, int &vertex,
         int &edge) {
  visited.insert(start);
  vertex++;
  for (auto &val : adj[start]) {
    edge++;
    if (visited.find(val) == visited.end()) {
      dfs(val, visited, adj, vertex, edge);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  set<int> visited;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a - 1].push_back(b - 1);
    adj[b - 1].push_back(a - 1);
  }

  for (int i = 0; i < n; i++) {
    if (visited.find(i) == visited.end()) {
      int vertex = 0, edge = 0;
      dfs(i, visited, adj, vertex, edge);
      edge /= 2;

      if (edge != (1LL * vertex * (vertex - 1)) / 2) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
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
