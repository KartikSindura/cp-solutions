#include <bits/stdc++.h>
using namespace std;

int main() {
  int vp, vd, t, f, c;
  int count = 0;
  cin >> vp >> vd >> t >> f >> c;

  if (vd <= vp) {
    cout << 0 << endl;
    return 0;
  }

  double p = vp * t;
  double d = 0;

  while (p < c) {
    double overtake = (p - d) / (vd - vp);
    if (p + vp * overtake >= c) {
      break;
    }
    p += vp * overtake;
    count++;
    double return_time = p / vd;
    p += vp * (return_time + f);
    d = 0;
  }

  cout << count << endl;
  return 0;
}
