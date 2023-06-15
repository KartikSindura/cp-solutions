#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> v;
    string line;

    while (n--) {
        cin >> line;
        v.push_back(line);
    }
    for (int i = 0; i < v.size(); i++) {
        int size = v[i].size();
        if (size > 10) {
            cout << v[i][0] << size - 2 << v[i][size - 1] << endl;
        } else {
            cout << v[i] << endl;
        }
    }
}