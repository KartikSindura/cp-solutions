#include <bits/stdc++.h>
using namespace std;

bool isPrime(int mum) {
    for (int i = 2; i < mum; i++) {
        if (mum % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    string ans = "YES";
    if (!isPrime(m)) {
        ans = "NO";
        cout << ans;
    } else {
        for (int i = n + 1; i < m; i++) {
            if (isPrime(i)) {
                ans = "NO";
                break;
            }
        }
        cout << ans;
    }
}