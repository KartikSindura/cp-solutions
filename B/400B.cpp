#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  int n, m;
  set<int> dist;
  bool flag = false;
  cin >> n >> m;
  while (n--) {
    string x;
    cin >> x;
    int G = x.find('G');
    int S = x.find('S');
    int diff = S - G;
    if (diff < 0) {
      flag = true;
      break;
    } else {
      dist.insert(diff);
    }
  }
  if (flag) {
    cout << -1;
  } else {
    cout << dist.size();
  }
}

// Think on paper, not on code.
// Read problem statement twice.
// Think pictorially.

// Range overlap check => !(b<c || d<a)
// cout << setprecision(int);
// cout << num;
