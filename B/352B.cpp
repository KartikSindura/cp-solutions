#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  int n;
  cin >> n;
  map<int, vector<int>> pos;
  lp(i, n) {
    int x;
    cin >> x;
    pos[x].push_back(i);
  }

  vector<pair<int, int>> res;
  for (auto &s : pos) {
    if (s.second.size() == 1) {
      res.push_back({s.first, 0});
      continue;
    }

    int d = s.second[1] - s.second[0];
    bool valid = true;
    for (int i = 2; i < s.second.size(); i++) {
      if (s.second[i] - s.second[i - 1] != d) {
        valid = false;
        break;
      }
    }
    if (valid) {
      res.push_back({s.first, d});
    }
  }

  cout << res.size() << endl;
  for (auto &s : res) {
    cout << s.first << " " << s.second << endl;
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
