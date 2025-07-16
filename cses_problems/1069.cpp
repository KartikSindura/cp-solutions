#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  string word;
  cin >> word;
  int maxe = 1;
  int curr = 1;
  for (int i = 0, j = 1; i < word.size() && j <= word.size(); i++, j++) {
    if (word[i] == word[j]) {
      curr++;
    } else {
      maxe = max(maxe, curr);
      curr = 1;
    }
  }
  cout << maxe;
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
