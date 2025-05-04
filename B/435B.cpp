#include <bits/stdc++.h>
#include <utility>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  string num;
  cin >> num;
  int k;
  cin >> k;
  int nn = 0;

  for (int i = 0; i < num.size(); i++) {
    if (num[i] == '9') {
      continue;
    }
    nn = i;
    break;
  }

  for (int i = nn; i < num.size() && k > 0; i++) {
    int maxDigit = num[i] - '0';
    int maxpos = i;
    for (int j = i; j < num.size() && j - i <= k; j++) {
      if (num[j] > num[maxpos]) {
        maxDigit = num[j] - '0';
        maxpos = j;
      }
    }
    for (int j = maxpos; j > i; j--) {
      swap(num[j], num[j - 1]);
    }

    k -= (maxpos - i);
  }
  cout << num << endl;
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
