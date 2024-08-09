#include <algorithm>
#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lp1(i, n) for (int i = 1; i <= n; i++)

string addStrings(string num1, string num2) {
  string result;
  int carry = 0;
  int i = num1.length() - 1;
  int j = num2.length() - 1;

  while (i >= 0 || j >= 0 || carry) {
    int digit1 = (i >= 0) ? num1[i] - '0' : 0;
    int digit2 = (j >= 0) ? num2[j] - '0' : 0;
    int sum = digit1 + digit2 + carry;

    result.push_back(sum % 10 + '0');
    carry = sum / 10;

    i--;
    j--;
  }

  reverse(result.begin(), result.end());
  return result;
}

string reverseNumber(string num) {
  while (num[num.size() - 1] == '0') {
    num.pop_back();
  }
  reverse(num.begin(), num.end());
  return num;
}

int main() {
  int t;
  cin >> t;
  lp(i, t) {
    string a, b;
    cin >> a >> b;
    string ans = reverseNumber(addStrings(reverseNumber(a), reverseNumber(b)));
    cout << ans << endl;
  }
}
