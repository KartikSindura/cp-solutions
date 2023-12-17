#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    vector<int> vec;
    while (t--) {
        int n;
        cin >> n;
        vec.push_back(n);
    }
    for (int i = 0; i < vec.size(); i++) {
        if (i == 0) {
            cout << abs(vec[i] - vec[i + 1]) << " "
                 << max(abs(vec[i] - vec[0]), abs(vec[i] - vec[vec.size() - 1]))
                 << endl;
        } else if (i == vec.size() - 1) {
            cout << abs(vec[i] - vec[i - 1]) << " "
                 << max(abs(vec[i] - vec[0]), abs(vec[i] - vec[vec.size() - 1]))
                 << endl;
        } else {
            cout << min(abs(vec[i] - vec[i + 1]), abs(vec[i] - vec[i - 1]))
                 << " "
                 << max(abs(vec[i] - vec[0]), abs(vec[i] - vec[vec.size() - 1]))
                 << endl;
        }
    }

    return 0;
}