#include <bits/stdc++.h>
using namespace std;

int main() {
    char shift;
    string data = "qwertyuiopasdfghjkl;zxcvbnm,./";
    string ans;
    string mole;
    cin >> shift;
    cin >> mole;
    if (shift == 'R') {
        for (int i = 0; i < mole.size(); i++) {
            int ind = data.find(mole[i]);
            ans += data[ind - 1];
        }

    } else if (shift == 'L') {
        for (int i = 0; i < mole.size(); i++) {
            int ind = data.find(mole[i]);
            ans += data[ind + 1];
        }
    }
    cout << ans;

    return 0;
}