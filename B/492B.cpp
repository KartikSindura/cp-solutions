#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lp1(i, n) for (int i = 1; i <= n; i++)

double solve() {
  int n, l;
  vector<int> vec;
  cin >> n >> l;

  lp(i, n) {
    int a;
    cin >> a;
    vec.push_back(a);
  }

  if (vec.size() < 2) {
    int ma = max(l - vec[0], vec[0]);
    return ma;
  }
  sort(vec.begin(), vec.end());

  double max_diff = max(vec[0] * 2, (l - vec[vec.size() - 1]) * 2);
  for (int i = 1; i < vec.size(); i++) {
    double diff = abs(vec[i] - vec[i - 1]);
    max_diff = max(diff, max_diff);
  }
  return max_diff / 2;
}

int main() { cout << fixed << setprecision(10) << solve() << endl; }
