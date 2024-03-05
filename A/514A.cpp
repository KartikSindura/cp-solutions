#include <bits/stdc++.h>
using namespace std;
int main() {
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        int num = str[i] - '0';
        if (i == 0 && num == 9) {
            continue;
        }
        if (num > 4) {
            str[i] = (9 - num) + '0';
        }
    }
    cout << str << endl;
    return 0;
}