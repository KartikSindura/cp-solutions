#include <bits/stdc++.h>
using namespace std;
// 4
// RLRL
// 2 4 6 10

int main() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<int> vec;
    int mini = 1000000000;

    while (n--) {
        int a;
        cin >> a;
        vec.push_back(a);
    }
    for (int i = 0; i < str.size() - 1; i++) {
        if (str[i] == 'R' && str[i + 1] == 'L') {
            int diff = vec[i + 1] - vec[i];
            if (diff % 2 == 0) {
                mini = min(diff / 2, mini);
            }
        }
    }
    if (mini == 1000000000) {
        cout << -1;
    } else {
        cout << mini;
    }

    return 0;
}