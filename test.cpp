#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  int count = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x == 0) {
      continue;
    }
    int ans = x & x - 1;
    if (ans == 0) {
      count++;
    }
  }
  cout << count << endl;
  return 0;
}
