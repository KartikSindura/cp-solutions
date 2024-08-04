#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
int magic_count = 0;

void sum(string s) {
  if (s.size() > 1) {
    magic_count++;
    int count = 0;
    lp(i, s.size()) { count += s[i] - '0'; }
    if (count > 9) {
      sum(to_string(count));
    }
  }
}

int main() {
  string n;
  cin >> n;
  sum(n);
  cout << magic_count << endl;
}
