#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lp1(i, n) for (int i = 1; i <= n; i++)

int main() {
  int n;
  cin >> n;
  string word;
  char ans[2001];
  cin >> word;

  int mid = n / 2;

  if (n % 2 == 0) {
    for (int i = 0; i < n; i += 2) {
      ans[mid - 1 - i / 2] = word[i];
      ans[mid + i / 2] = word[i + 1];
    }
  } else {
    ans[mid] = word[0];
    for (int i = 1; i < n; i += 2) {
      ans[mid - (i + 1) / 2] = word[i];
      ans[mid + (i + 1) / 2] = word[i + 1];
    }
  }
  ans[n] = '\0';
  cout << ans << endl;
  return 0;
}
