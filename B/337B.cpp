#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int screen = a * b;

  if (d * a <= c * b) {
    // try width
    int num = screen * c - a * (a * d);
    int den = screen * c;
    int g = gcd(num, den);
    cout << (num / g) << "/" << (den / g) << endl;
  } else {
    int num = screen * d - b * (b * c);
    int den = screen * d;
    int g = gcd(num, den);
    cout << (num / g) << "/" << (den / g) << endl;
  }
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
