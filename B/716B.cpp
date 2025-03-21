#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

string validate(string &sub) {
  map<char, int> m;
  vector<char> missing;
  for (char c = 'A'; c <= 'Z'; c++) {
    m[c] = 0;
  }

  lp(i, sub.size()) {
    if (sub[i] == '?') {
      continue;
    }
    m[sub[i]]++;
  }
  for (auto &val : m) {
    if (val.second > 1) {
      return "-1";
    } else if (val.second == 0) {
      missing.push_back(val.first);
    }
  }

  lp(i, sub.size()) {
    if (sub[i] == '?') {
      if (!missing.empty()) {
        sub[i] = missing[missing.size() - 1];
        missing.pop_back();
      }
    }
  }
  return sub;
}

int main() {
  string word;
  cin >> word;
  unordered_map<char, int> m;

  for (int i = 0, j = 25; j < word.size(); i++, j++) {
    string sub = word.substr(i, 26);
    string res = validate(sub);
    if (res != "-1") {
      word.replace(i, 26, sub, 0, 26);
      lp(j, word.size()) {
        if (word[j] == '?') {
          word[j] = 'A';
        }
      }
      cout << word << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}

// Think on paper, not on code.
// Read problem statement twice.
// Think pictorially.

// Range overlap check => !(b<c || d<a)
// cout << setprecision(int);
// cout << num;
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
