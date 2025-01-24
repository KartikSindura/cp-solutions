#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m), b(k);
    vector<int> valid(n + 1, 0);

    lp(i, m) { cin >> a[i]; }

    lp(i, k) {
      cin >> b[i];
      valid[b[i]] = 1;
    }

    if (n > k + 1) {
      string s(m, '0');
      cout << s << endl;
    } else if (n == k) {
      string s(m, '1');
      cout << s << endl;
    } else {
      string s = "";
      lp(i, m) {
        if (valid[a[i]] == 0) {
          s += '1';
        } else {
          s += '0';
        }
      }
      cout << s << endl;
    }
  }
}

// 2 2 1
// 1 2
// 2
