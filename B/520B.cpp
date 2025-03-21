#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int bfs(int start, int m) {
  set<int> visited = {start};
  queue<int> q;
  q.push(start);
  int depth = 0;

  while (!q.empty()) {
    int size = q.size();

    for (int i = 0; i < size; i++) {
      int front = q.front();
      // cout << front << endl;
      q.pop();

      if (front == m) {
        return depth;
      }

      if (front * 2 <= 1e4 && visited.find(front * 2) == visited.end()) {
        visited.insert(front * 2);
        q.push(front * 2);
      }

      if (front - 1 >= 1 && visited.find(front - 1) == visited.end()) {
        visited.insert(front - 1);
        q.push(front - 1);
      }
    }
    depth++;
  }
  return -1;
}

int main() {
  int n, m;
  cin >> n >> m;
  cout << bfs(n, m);
}

// Think on paper, not on code.
// Read problem statement twice.
// Think pictorially.

// Range overlap check => !(b<c || d<a)
// cout << setprecision(int);
// cout << num;
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
