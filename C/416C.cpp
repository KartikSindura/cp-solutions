#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int acceptedReq = 0;
int totalMoney = 0;
vector<pair<int, int>> ans;

void findandpoptable(int s, int m, vector<pair<int, int>> &tables, int idx_s) {
  for (int i = 0; i < tables.size(); i++) {
    if (s <= tables[i].first) {
      totalMoney += m;
      acceptedReq++;
      ans.push_back({idx_s, tables[i].second});
      tables.erase(tables.begin() + i);
      return;
    }
  }
}

int main() {
  int n;
  cin >> n;
  vector<tuple<int, int, int>> req(n);
  lp(i, n) {
    int s, m;
    cin >> s >> m;
    req[i] = {s, m, i + 1};
  }
  int k;
  cin >> k;
  vector<pair<int, int>> tables(k);
  lp(i, k) {
    int r;
    cin >> r;
    tables[i] = {r, i + 1};
  }

  sort(req.begin(), req.end(),
       [](tuple<int, int, int> a, tuple<int, int, int> b) {
         return get<1>(a) > get<1>(b);
       });
  sort(tables.begin(), tables.end(), [](pair<int, int> a, pair<int, int> b) {
    return get<0>(a) < get<0>(b);
  });

  for (int i = 0; i < req.size(); i++) {
    findandpoptable(get<0>(req[i]), get<1>(req[i]), tables, get<2>(req[i]));
  }

  cout << acceptedReq << " " << totalMoney << endl;
  for (auto &[s, m] : ans) {
    cout << s << " " << m << endl;
  }
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
