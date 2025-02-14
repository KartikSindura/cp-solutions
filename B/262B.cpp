#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> incomes(n);
  lp(i, n) { cin >> incomes[i]; }
  for (int i = 0; i < n && k > 0 && incomes[i] < 0; i++, k--) {
    incomes[i] *= -1;
  }

  ll sum = accumulate(incomes.begin(), incomes.end(), 0);
  if (k % 2 != 0) {
    sum -= 2 * *min_element(incomes.begin(), incomes.end());
  }

  cout << sum;
}

// Think on paper, not on code.
// Read problem statement twice.
// Think pictorially.

// Range overlap check => !(b<c || d<a)
// cout << setprecision(int);
// cout << num;
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
