#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  int n;
  int count = 0;
  stack<int> s;
  cin >> n;
  lp(i, n) {
    ll l, h;
    cin >> l >> h;

    if (s.empty()) {
      count++;
      s.push(h);
    } else {
      while (s.top() > h) {
        s.pop();
        if (s.empty()) {
          break;
        }
      }
      if (s.empty()) {
        count++;
        s.push(h);
      } else {
        if (s.top() == h) {
          continue;
        } else {
          count++;
          s.push(h);
        }
      }
    }
  }
  cout << count << endl;
}
