#include <bits/stdc++.h>
#include <cctype>
#include <unordered_map>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  string s;
  cin >> s;
  string t;
  cin >> t;
  // unordered_map<char, int> smap;
  unordered_map<char, int> tmap;
  int yay, whoops = 0;
  // for (auto &val : s) {
  //   smap[val]++;
  // }
  for (auto &val : t) {
    tmap[val]++;
  }
  for (int val = 0; val < s.length(); val++) {
    // for (auto &v : tmap) {
    //   cout << v.first << " " << v.second << endl;
    // }
    // cout << endl;
    // cout << s[val] << endl;
    // cout << s << endl;

    if (tmap.find(s[val]) != tmap.end() && tmap[s[val]] > 0) {
      yay++;
      tmap[s[val]]--;
      s.erase(val, 1);
      val--;
    }
  }
  for (auto &val : s) {
    if (tmap.find(tolower(val)) != tmap.end() && tmap[tolower(val)] > 0) {
      whoops++;
      tmap[tolower(val)]--;
    } else if (tmap.find(toupper(val)) != tmap.end() &&
               tmap[toupper(val)] > 0) {
      whoops++;
      tmap[toupper(val)]--;
    }
  }
  cout << yay << " " << whoops << endl;
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
