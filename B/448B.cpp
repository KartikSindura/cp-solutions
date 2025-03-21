#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

bool isSubset(unordered_map<char, int> &tm, unordered_map<char, int> &sm) {
  for (auto &[key, val] : tm) {
    auto it = sm.find(key);
    if (it == sm.end() || it->second < val) {
      return false;
    }
  }
  return true;
}

bool isLinearSubset(string &t, string &s) {
  int i = 0, j = 0;
  while (i < s.size() && j < t.size()) {
    if (s[i] == t[j]) {
      j++;
    }
    i++;
  }
  return j == t.size();
}

int main() {
  string s, t;
  cin >> s >> t;
  unordered_map<char, int> sm, tm;

  lp(i, s.size()) { sm[s[i]]++; }

  lp(i, t.size()) { tm[t[i]]++; }

  bool check = sm == tm;
  bool subset = isSubset(tm, sm);

  if (s.size() < t.size() || !subset) {
    cout << "need tree" << endl;
  } else if (check && s != t) {
    cout << "array" << endl;
  } else if (s.size() > t.size()) {
    if (isLinearSubset(t, s)) {
      cout << "automaton" << endl;
    } else {
      cout << "both" << endl;
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
