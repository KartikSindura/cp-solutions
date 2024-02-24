#include <bits/stdc++.h>
using namespace std;

string foo(int n, int m) {
    char ch;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ch;
            if (ch == 'C' || ch == 'M' || ch == 'Y') {
                return "#Color";
            }
        }
    }
    return "#Black&White";
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << foo(n , m);
    return 0;
}