#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<ll> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  vector<tuple<int, int, int>> ops(m);
  for (int i = 0; i < m; i++) {
    int l, r, d;
    cin >> l >> r >> d;
    ops[i] = {l, r, d};
  }
  vector<int> op_count(m + 2, 0);
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    op_count[x - 1]++;
    op_count[y]--;
  }

  for (int i = 1; i < m; i++) {
    op_count[i] += op_count[i - 1];
  }

  vector<ll> main_arr(n + 1, 0);
  for (int i = 0; i < m; i++) {
    int l = get<0>(ops[i]);
    int r = get<1>(ops[i]);
    int d = get<2>(ops[i]);
    main_arr[l - 1] += 1LL * d * op_count[i];
    main_arr[r] -= 1LL * d * op_count[i];
  }

  for (int i = 1; i < n; i++) {
    main_arr[i] += main_arr[i - 1];
  }
  for (int i = 0; i < n; i++) {
    cout << arr[i] + main_arr[i] << " ";
  }
}
