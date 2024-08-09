#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lp1(i, n) for (int i = 1; i <= n; i++)

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a >= c) {
        cout << a;
        return;
    }
    int n = (c - a) / (b + d);
    a += n * b;
    c -= n * d;
    if (a + b <= c) {
        cout << a + b;
    } else {
        cout << c;
    }
}

int main() { solve(); }