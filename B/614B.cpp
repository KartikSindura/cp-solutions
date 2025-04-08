#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

bool check_ugly(string &word) {
  if (word == "1") {
    return false;
  }
  if (word[0] != '1') {
    return true;
  }
  for (int i = 1; i < word.size(); i++) {
    if (word[i] != '0')
      return true;
  }
  return false;
}

int main() {
  int n;
  cin >> n;
  bool found = false;
  string ugly = "1";
  int total_zero = 0;
  lp(i, n) {
    string num;
    cin >> num;
    if (num == "0") {
      cout << 0;
      return 0;
    }
    if (!check_ugly(num)) {
      total_zero += num.size() - 1;
    } else {
      ugly = num;
    }
  }
  string zeros(total_zero, '0');
  cout << ugly << zeros << endl;
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
