#include <bits/stdc++.h>
#include <cmath>
#include <iomanip>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  int n, m, k, A, B;
  cin >> n;
  int max_r1 = 0, max_p1 = 0, min_p2 = 5001;
  while (n--) {
    int x;
    cin >> x;
    max_r1 = max(max_r1, x);
  }
  cin >> m;
  while (m--) {
    int y;
    cin >> y;
    max_p1 = max(max_p1, y);
  }
  cin >> k;
  while (k--) {
    int z;
    cin >> z;
    min_p2 = min(min_p2, z);
  }
  cin >> A >> B;
  float a = B * max_p1;
  float b = A * min_p2 + B * max_p1;

  float r2 = max_r1 * (sqrt(a / b));
  cout << setprecision(13);
  cout << r2;
}

// Think on paper, not on code.
// Read problem statement twice.
// Think pictorially.

// Range overlap check => !(b<c || d<a)
