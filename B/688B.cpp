#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  string n;
  cin >> n;
  cout << n;
  for (int i = n.length() - 1; i >= 0; i--) {
    cout << n[i];
  }
}
