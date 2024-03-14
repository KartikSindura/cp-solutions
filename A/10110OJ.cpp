#include <bits/stdc++.h>
using namespace std;

bool perfect(long long inp) {
    long long sq = sqrt(inp);
    if (sq * sq == inp) {
        return true;
    }
    return false;
}

int main() {
    long long inp;
    while (cin >> inp) {
        if (inp == 0) {
            break;
        }
        if (perfect(inp)) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }

    return 0;
}
