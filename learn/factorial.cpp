#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int factorial(int n) {
  int ans = 1;
  for (int i = 2; i <= n; i++) {
    ans *= i;
  }
  return ans;
}

int fact(int n) {
  if (n == 1) {
    return 1;
  }
  return fact(n - 1) * n;
}

void triangle(int n) {
  int w = n;
  for (int i = n; i >= 0; i--) {
    cout << endl;
    w--;
    for (int j = 0; j < i; j++) {
      cout << "*";
    }
  }
  cout << endl;
}

void tri(int levels) {
  if (levels == 0) {
    return;
  }
  tri(levels - 1);
  lp(i, levels) { cout << "*"; }
  cout << endl;
}

int count_3n_1_seq(int n) {
  // cout << n << " ";
  if (n == 1 || n == 0) {
    return 1;
  }
  if (n % 2 == 0) {
    return 1 + count_3n_1_seq(n / 2);
  }
  return 1 + count_3n_1_seq(n * 3 + 1);
}

void printNumber(int n) {
  // 1234
  if (n) {
    printNumber(n / 10);
    cout << n % 10;
  }
}

int main() {
  // cout << factorial(5) << endl;
  // cout << fact(4) << endl;
  // triangle(5);
  // tri(5);
  // int n;
  // cin >> n;
  // cout << count_3n_1_seq(n);
  printNumber(123);
}

// Think on paper, not on code.
// Read problem statement twice.
// Think pictorially.

// Range overlap check => !(b<c || d<a)
// cout << setprecision(int);
// cout << num;
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
