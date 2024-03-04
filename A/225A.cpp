#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, top;
    cin >> n >> top;
    string ans = "YES";
    while (n--) {
        int a, b;
        cin >> a >> b;
        if (a == top || a == 7 - top || b == top || b == 7 - top) {
            ans = "NO";
            break;
        }
    }
    cout << ans;

    return 0;
}