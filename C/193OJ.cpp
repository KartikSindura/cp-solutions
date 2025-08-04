#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

vector<int> color(101, 0);
vector<int> best_black;
map<int, vector<int>> adj;

bool valid(int node, int col) {
  if (col == 1) {
    for (auto &val : adj[node]) {
      if (color[val] == 1) {
        return false;
      }
    }
  }
  return true;
}

void backtrack(int n, int node, vector<int> &current_black) {
  if (node > n) {
    if (current_black.size() > best_black.size()) {
      best_black = current_black;
    }
    return;
  }

  if (valid(node, 1)) {
    color[node] = 1;
    current_black.push_back(node);
    backtrack(n, node + 1, current_black);
    current_black.pop_back();
    color[node] = 0;
  }

  color[node] = 0;
  backtrack(n, node + 1, current_black);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    adj.clear();
    for (int i = 0; i < k; i++) {
      int a, b;
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    best_black.clear();
    vector<int> current_black;
    backtrack(n, 1, current_black);
    cout << best_black.size() << endl;
    for (int i = 0; i < best_black.size(); i++) {
      cout << best_black[i] << (i + 1 < best_black.size() ? ' ' : '\n');
    }
  }
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
