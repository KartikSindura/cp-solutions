#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  int n;
  cin >> n;
  if (n < 4 && n != 1) {
    cout << "NO SOLUTION";
    return 0;
  } else {
    vector<int> vec(n);
    if (n % 2 == 0) {
      vec[(n / 2) - 1] = n;
      for (int i = n - 1, j = 1; i >= n / 2; i--, j += 2) {
        vec[i] = j;
      }
      for (int i = (n / 2) - 2, j = 2; i >= 0; i--, j += 2) {
        vec[i] = j;
      }
      swap(vec[n / 2], vec[n / 2 + 1]);
    } else {
      vec[(n / 2)] = n;
      for (int i = n - 1, j = 1; i >= n / 2; i--, j += 2) {
        vec[i] = j;
      }
      for (int i = (n / 2) - 1, j = 2; i >= 0; i--, j += 2) {
        vec[i] = j;
      }
    }
    for (int i = 0; i < vec.size(); i++) {
      if (i == vec.size() - 1) {
        cout << vec[i];
      } else {
        cout << vec[i] << " ";
      }
    }
  }
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
