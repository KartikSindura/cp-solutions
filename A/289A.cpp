#include <bits/stdc++.h>
using namespace std;
// 2 3
// 1 2
// 3 4

int main() {
    int n, k;
    cin >> n >> k;
    int count = 0;
    while (n--) {
        int a, b;
        cin >> a >> b;
        count += b - a + 1;
    }
    count %= k;
    if (count != 0) {
        count = k - count;
    }

    cout << count;
    return 0;
}