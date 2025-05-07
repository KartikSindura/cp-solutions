#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  string s;
  cin >> s;
  int m;
  cin >> m;
  int hex = (s.size() + 1) / 2;
  vector<int> rev(hex, 0);
  while (m--) {
    int x;
    cin >> x;
    if (x <= hex) {
      rev[x - 1]++;
    }
  }
  for (int i = 1; i < rev.size(); i++) {
    rev[i] += rev[i - 1];
  }
  for (int i = 0; i < rev.size(); i++) {
    if (rev[i] % 2 != 0) {
      swap(s[i], s[s.size() - i - 1]);
    }
  }
  cout << s << endl;
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
