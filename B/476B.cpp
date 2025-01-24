#include <bits/stdc++.h>
#include <iomanip>
#include <ios>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

double fact(int n) {
  if (n == 0)
    return 1;
  double res = 1;
  for (int i = 2; i <= n; i++)
    res = res * i;
  return res;
}

double nCr(int n, int r) { return fact(n) / (fact(r) * fact(n - r)); }

int main() {
  string s1, s2;
  double prob = 0.0;
  int fi = 0, in = 0, ques = 0;
  cin >> s1 >> s2;

  lp(i, s1.size()) {
    if (s1[i] == '+') {
      fi++;
    } else {
      fi--;
    }

    if (s2[i] == '+') {
      in++;
    } else if (s2[i] == '-') {
      in--;
    } else {
      ques++;
    }
  }
  int cases = 1 << ques;
  if (ques == 0) {
    if (fi == in) {
      cout << fixed << setprecision(12) << 1.0000000000 << endl;
    } else {
      cout << fixed << setprecision(12) << prob << endl;
    }
  } else {
    int diff = fi - in;
    if ((diff + ques) % 2 != 0 || abs(diff) > ques) {
      cout << fixed << setprecision(12) << prob;
    } else {
      int x = (diff + ques) / 2;
      cout << fixed << setprecision(12) << nCr(ques, x) / cases;
    }
  }
}
// +-+-- -1
// ????+ 1
// -2+4 = 2/2 = 1
// 10 7 3+3/2=3
