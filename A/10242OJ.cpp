#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)

int main() {
    float x1, y1, x2, y2, x3, y3, x4, y4;
    // cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4) {
        // float xa = x1 + x3 - x4;
        // float ya = y1 + y3 - y4;

        float xb = x1 + x4 - x3;
        float yb = y1 + y4 - y3;

        // float xc = x4 + x3 - x1;
        // float yc = y4 + y3 - y1;

        // cout << xa << " " << ya << endl;
        cout << fixed;
        cout << setprecision(3);
        cout << xb << " " << yb << endl;
        // cout << xc << " " << yc << endl;
    }

    return 0;
}
// 0.000 0.000 0.000 1.000 0.000 1.000 1.000 1.000
// 1.000 0.000 3.500 3.500 3.500 3.500 0.000 1.000
// 1.866 0.000 3.127 3.543 3.127 3.543 1.412 3.145
