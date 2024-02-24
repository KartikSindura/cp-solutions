#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    string word;
    cin >> t;
    cin >> word;
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    string data = "abcdefghijklmnopqrstuvwxyz";
    string ans;
    set<char> s;
    for (int i = 0; i < word.size(); i++) {
        s.insert(word[i]);
    }
    if (s.size() >= 26) {
        for (auto &val : s) {
            ans += val;
        }
        if (ans == data) {
            cout << "YES";
        } else {
            cout << "NO";
        }

    } else {
        cout << "NO";
    }

    return 0;
}