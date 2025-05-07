#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  int n;
  cin >> n;
  string s;
  lp(i, n) { cin >> s; }
  string result = "";

  for (char c : s) {
    if (c == '2')
      result += "2";
    else if (c == '3')
      result += "3";
    else if (c == '4')
      result += "322";
    else if (c == '5')
      result += "5";
    else if (c == '6')
      result += "53";
    else if (c == '7')
      result += "7";
    else if (c == '8')
      result += "7222";
    else if (c == '9')
      result += "7332";
  }

  sort(result.rbegin(), result.rend());
  cout << result << endl;
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
