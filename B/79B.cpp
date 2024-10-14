#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  int n, m, k, t;
  vector<pair<int, int>> wastes;
  cin >> n >> m >> k >> t;
  wastes.resize(k);
  lp(i, k) { cin >> wastes[i].first >> wastes[i].second; }
  lp(j, t) {
    int a, b;
    cin >> a >> b;

    int veg = (a - 1) * m + (b);
    int count = 0;
    bool isWaste = false;

    for (auto &val : wastes) {
      if (val.first == a && val.second == b) {
        cout << "Waste" << endl;
        isWaste = true;
        break;
      } else if (((val.first - 1) * m + (val.second)) < veg) {
        count++;
      }
    }

    if (!isWaste) {
      int ans = (veg - count) % 3;
      if (ans == 0) {
        cout << "Grapes" << endl;
      } else if (ans == 1) {
        cout << "Carrots" << endl;
      } else {
        cout << "Kiwis" << endl;
      }
    }
  }
}
