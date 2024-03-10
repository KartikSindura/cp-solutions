
#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    if (str == "0" || str == "1") {
        cout << 0;
    } else {
        bitset<101> bit(str);
        if (bit.count() > 1) {
            cout << (str.length() + 1) / 2;
        } else {
            cout << str.length() / 2;
        }
    }
}