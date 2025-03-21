#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

void dfs(int start, vector<bool> &visited, vector<vector<int>> &adj) {
  visited[start] = true;
  for (auto &val : adj[start]) {
    if (!visited[val]) {
      dfs(val, visited, adj);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> edges;
  vector<vector<int>> adj(n + 1);

  lp(i, m) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  int score = 0;
  vector<bool> visited(n + 1, false);

  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      dfs(i, visited, adj);
      score++;
    }
  }
  cout << score << endl;
  ll result = 1;
  for (int i = 0; i < n - score; i++) {
    result *= 2;
  }

  cout << result << endl;
}

// Think on paper, not on code.
// Read problem statement twice.
// Think pictorially.

// Range overlap check => !(b<c || d<a)
// cout << setprecision(int);
// cout << num;
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
