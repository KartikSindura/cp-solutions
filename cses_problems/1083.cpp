#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  int n;
  cin >> n;
  vector<int> arr;
  arr.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int a;
    cin >> a;
    arr[a]++;
  }
  for (int i = 1; i <= arr.size(); i++) {
    if (arr[i] == 0) {
      cout << i;
    }
  }
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
