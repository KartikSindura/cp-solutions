#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lp1(i, n) for (int i = 1; i <= n; i++)

int main() {
  string coin;
  string ans = "xxx";
  map<char, int> m = {{'A', 0}, {'B', 0}, {'C', 0}};
  // vector<pair<char, int>> m = {{'A', 0}, {'B', 0}, {'C', 0}};
  lp(i, 3) {
    cin >> coin;
    if (coin[1] == '>') {
      m[coin[0]]++;
    } else {
      m[coin[2]]++;
    }
  }
  if (m['A'] == m['B'] && m['B'] == m['C']) {
    cout << "Impossible";
  } else {
    for (auto &val : m) {
      ans[val.second] = val.first;
    }
    cout << ans;
  }
}
