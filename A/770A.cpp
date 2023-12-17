#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string ans = "";
    for (int i = 0, count = 0; i < n; i++) {
        if (count == k) {
            count = 0;
        }
        count++; 
        ans += char(count + 96);
    }
    cout << ans;
}