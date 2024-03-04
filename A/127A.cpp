#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    double dist = 0;
    double a, b;
    cin >> a >> b;
    n--;
    while (n--) {
        double c, d;
        cin >> c >> d;
        dist += sqrt(pow((a - c), 2) + pow((b - d), 2));
        a = c;
        b = d;
    }
    cout << setprecision(9) << fixed << (dist / 50) * k;
    return 0;
}