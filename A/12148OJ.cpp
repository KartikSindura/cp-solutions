#include <bits/stdc++.h>
using namespace std;

int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool check(int d, int m, int y, int c, int dm, int mm, int ym, int cm) {
    if (--dm == 0) {
        if (--mm == 0) {
            --ym;
            mm = 12;
        }
        dm = days[m - 1];
    }
    bool leap = ym % 4 == 0 && (ym % 100 != 0 || ym % 400 == 0);
    if (leap && mm == 2) {
        dm = 29;
    }
    // cout << endl << d << " " << m << " " << y << " " << c << " " << endl;
    // cout << dm << " " << mm << " " << ym << " " << cm << " " << endl;
    return (d == dm && m == mm && y == ym);
}
int main() {
    int n;
    int d = 0, m = 0, y = 0, c = 0;
    while (cin >> n, n) {
        int total_cap = 0, count = 0;
        while (n--) {
            int dm, mm, ym, cm;
            cin >> dm >> mm >> ym >> cm;
            if (check(d, m, y, c, dm, mm, ym, cm)) {
                count++;
                total_cap += cm - c;
            }
            d = dm;
            m = mm;
            y = ym;
            c = cm;
        }
        cout << count << " " << total_cap;
    }
}
