#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

class Solution {
public:
  int totalNumbers(vector<int> &digits) {
    int n = digits.size();
    set<int> st;
    vector<int> even;
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        even.push_back(i);
      }
    }

    for (auto &val : even) {
      int s = 0;
      for (int i = 0; i < n; i++) {
        if (digits[i] == 0 || digits[i] == digits[val]) {
          continue;
        }
        for (int j = 0; j < n; j++) {
          if (digits[j] != digits[val] && digits[j] != digits[i]) {
            s = digits[val] * 100;
            s += (digits[i] * 10) + digits[j];
            cout << s << endl;
            st.insert(s);
          }
        }
      }
    }
    return st.size();
  }
};
// Think on paper, not on code.
// Read problem statement twice.
// Think pictorially.

// Range overlap check => !(b<c || d<a)
// cout << setprecision(int);
// cout << num;
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
