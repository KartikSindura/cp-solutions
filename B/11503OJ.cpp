#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

map<string, string> parents;
map<string, int> sizes;

string find_set(string name) {
  if (name == parents[name])
    return name;
  return parents[name] = find_set(parents[name]);
}

void link(string u, string v) {
  if (sizes[u] > sizes[v]) {
    swap(u, v);
  }
  parents[u] = v;
  sizes[v] += sizes[u];
}

int union_set(string u, string v) {
  u = find_set(u);
  v = find_set(v);
  if (u != v) {
    link(u, v);
  }
  return max(sizes[u], sizes[v]);
}

int main() {
  int t, n;
  string u, v;
  cin >> t;
  while (t--) {
    cin >> n;
    parents.clear();
    sizes.clear();
    while (n--) {
      cin >> u >> v;
      if (parents.count(u) == 0) {
        parents[u] = u;
        sizes[u] = 1;
      }
      if (parents.count(v) == 0) {
        parents[v] = v;
        sizes[v] = 1;
      }

      cout << union_set(u, v) << endl;
    }
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
