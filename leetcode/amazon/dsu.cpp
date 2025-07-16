#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

vector<int> parent, sizes;

void make_set(int v) {
  parent[v] = v;
  sizes[v] = 1;
}

int find_set(int v) {
  if (parent[v] == v) {
    return v;
  }
  return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (sizes[a] < sizes[b]) {
      swap(a, b);
    }
    parent[b] = a;
    sizes[a] += sizes[b];
  }
}

int main() {}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
