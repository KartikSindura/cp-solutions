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
      if (digits[i] % 2 == 0) {
        even.push_back(i);
      }
      // for (auto &val : digits) {
      //   if (val % 2 == 0) {
      //     even.push_back(val);
      //   }
    }

    for (auto &val : even) {
      int s = 0;
      for (int i = 0; i < n; i++) {
        if (digits[i] == 0 || i == val) {
          continue;
        }
        for (int j = 0; j < n; j++) {
          if (j != val && j != i) {
            s = digits[i] * 100;
            s += (digits[j] * 10 + digits[val]);
            cout << s << endl;
            st.insert(s);
          }
        }
      }
    }
    return st.size();
  }
};

int main() {
  Solution h = *new Solution();
  // vector<int> digits = {6, 6, 6};
  // vector<int> digits = {0, 2, 2};
  // vector<int> digits = {1, 2, 3, 4};
  vector<int> digits = {1, 3, 5};
  cout << h.totalNumbers(digits);
}
// Think on paper, not on code.
// Read problem statement twice.
// Think pictorially.

// Range overlap check => !(b<c || d<a)
// cout << setprecision(int);
// cout << num;
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
