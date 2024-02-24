#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> m;
    int n;
    cin >> n;
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        if (m.find(str) != m.end()) {
            m[str]++;
        } else {
            m.insert({str, 1});
        }
    }
    pair<string, int> p;
    for (auto &v : m) {
        if (v.second > p.second) {
            p.first = v.first;
            p.second = v.second;
        }
    }
    cout << p.first;
    return 0;
}