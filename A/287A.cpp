#include <bits/stdc++.h>
using namespace std;

// #.##
// ##.#
// #.##
// ##.#
char inp[4][4];
bool check(int i, int j) {
    if (i + 1 == 4 || j + 1 == 4) {
        return false;
    }
    return (inp[i][j] == inp[i][j + 1] && inp[i][j] == inp[i + 1][j]);
}
bool rcheck(int i, int j) {
    if (i - 1 == -1 || j - 1 == -1) {
        return false;
    }
    return (inp[i][j] == inp[i][j - 1] && inp[i][j] == inp[i - 1][j]);
}
bool dlcheck(int i, int j) {
    if (i + 1 == 4 || j - 1 == -1) {
        return false;
    }
    return (inp[i][j] == inp[i][j - 1] && inp[i][j] == inp[i + 1][j]);
}
bool trcheck(int i, int j) {
    if (i - 1 == -1 || j + 1 == 4) {
        return false;
    }
    return (inp[i][j] == inp[i][j + 1] && inp[i][j] == inp[i - 1][j]);
}

int main() {
    bool flag = false;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> inp[i][j];
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (check(i, j)) {
                flag = true;
                goto label;
            }
        }
    }
    for (int i = 3; i >= 0; i--) {
        for (int j = 3; j >= 0; j--) {
            if (rcheck(i, j)) {
                flag = true;
                goto label;
            }
        }
    }
    for (int i = 3; i >= 0; i--) {
        for (int j = 3; j >= 0; j--) {
            if (dlcheck(i, j)) {
                flag = true;
                goto label;
            }
        }
    }
    for (int i = 3; i >= 0; i--) {
        for (int j = 3; j >= 0; j--) {
            if (trcheck(i, j)) {
                flag = true;
                goto label;
            }
        }
    }
label:
    if (flag) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}