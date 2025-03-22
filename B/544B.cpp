#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  int n, k;
  cin >> n >> k;
  int even_count = 0, odd_count = 0;

  lp(i, n * n) {
    if ((i + 1) % 2 == 0) {
      even_count++;
    } else {
      odd_count++;
    }
  }
  if (k > odd_count) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
      string word = "";
      for (int j = 0; j < n; j++) {
        if (k > 0) {
          if (j % 2 == 0 && i % 2 == 0) {
            word.append("L");
            k--;
          } else if (j % 2 != 0 && i % 2 != 0) {
            word.append("L");
            k--;
          } else {
            word.append("S");
          }
        } else {
          word.append("S");
        }
      }
      cout << word << endl;
    }
  }
}

// Think on paper, not on code.
// Read problem statement twice.
// Think pictorially.

// Range overlap check => !(b<c || d<a)
// cout << setprecision(int);
// cout << num;
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
