#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    int count = t;
    set<int> s;
    while (t--) {
        vector<int> res;
        int n;
        cin >> n;
        if (n == count) {
            count--;
            res.push_back(n);
            while (s.find(count) != s.end()) {
                s.erase(count);
                res.push_back(count);
                count--;
            }
            for (auto &val : res) {
                cout << val << " ";
            }
            cout << endl;
        } else {
            s.insert(n);
            cout << endl;
        }
    }
    return 0;
}