#include <bits/stdc++.h>
using namespace std;

// bool check(int a, int b, int c, int d) {
//     if (r1 == ())
// }

int main() {
    int r1, r2, c1, c2, d1, d2;
    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
    int a, b, c, d;
    int a_range = min({d1, c1, r1});
    bool found = false;
    for (int i = 0; i < a_range; i++) {
        a = i + 1;
        d = d1 - a;
        b = c2 - d;
        c = r2 - d;

        if ((d1 == (a + d)) && (r1 == (a + b)) && (r2 == (c + d)) && (c1 == (a + c)) &&
            (c2 == (b + d)) && (d2 == (b + c))) {
            found = true;
            break;
        }
    }
    set<int> s;
    s.insert(a);
    s.insert(b);
    s.insert(c);
    s.insert(d);
    if (found && (a >= 1 && a <= 9 && b >= 1 && b <= 9 && c >= 1 && c <= 9 && d >= 1 &&
         d <= 9) &&
        s.size() == 4) {
        cout << a << " " << b << endl;
        cout << c << " " << d;
    } else {
        cout << -1;
    }

    return 0;
}