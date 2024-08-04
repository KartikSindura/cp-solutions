#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)

int main() {
  string coin;
  char greater, greatest, least;
  vector<string> order;
  lp(i, 3) {

    cin >> coin;
    if (coin[1] == '<') {
      char temp = coin[0];
      coin[0] = coin[2];
      coin[0] = temp;
      coin[1] = '>';
    }
    order.push_back(coin);
  }

  for (auto &val : order) {
    if (greater == val[0]) {
      greatest = val[0];
    } else {
      greater = val[0];
    }
  }
}
