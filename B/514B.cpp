#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int count = 0;
  vector<int> visited(n);
  vector<pair<int, int>> enemies;

  lp(i, n) {
    int x, y;
    cin >> x >> y;
    enemies.push_back({x, y});
  }

  lp(i, n) {
    if (!visited[i]) {
      count++;
      visited[i] = 1;
      lp(j, n) {
        if (visited[j]) {
          continue;
        }
        if (((enemies[i].first - a) * (enemies[j].second - b) ==
             (enemies[j].first - a) * (enemies[i].second - b))) {
          visited[j] = 1;
        }
      }
    }
  }
  cout << count << endl;
}

// Think on paper, not on code.
// Read problem statement twice.
// Think pictorially.

// Range overlap check => !(b<c || d<a)
// cout << setprecision(int);
// cout << num;
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
