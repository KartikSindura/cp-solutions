#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lp1(i, n) for (int i = 1; i <= n; i++)

int main() {
  int n;
  cin >> n;
  int arr[100005];
  lp1(i, n) {
    int a;
    cin >> a;
    arr[a] = i;
  }

  int m;
  ll vasya = 0, petya = 0;
  cin >> m;
  lp(i, m) {
    int q;
    cin >> q;
    vasya += arr[q];
    petya += n - arr[q] + 1;
  }

  cout << vasya << " " << petya;
}
