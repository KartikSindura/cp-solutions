#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  int n;
  set<int> s;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    s.insert(x);
  }

  if (s.size() >= 4) {
    cout << "NO";
  } else if (s.size() <= 2) {
    cout << "YES";
  } else if (s.size() == 3) {
    auto it = s.begin();
    int first = *it;
    ++it;
    int second = *it;
    ++it;
    int third = *it;
    if (abs(first - second) == abs(second - third)) {
      cout << "YES";
    } else {
      cout << "NO";
    }
  }
}

// Think on paper, not on code.
// Read problem statement twice.
// Think pictorially.

// Range overlap check => !(b<c || d<a)
// cout << setprecision(int);
// cout << num;
