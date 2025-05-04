#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  string s;
  cin >> s;
  map<char, int> freq;

  for (auto &val : s) {
    freq[val]++;
  }

  int odd_count = 0;

  for (auto &val : freq) {
    if (val.second % 2 != 0) {
      odd_count++;
    }
  }

  if (odd_count == 0 || odd_count % 2 == 1) {
    cout << "First" << endl;
  } else {
    cout << "Second" << endl;
  }
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
