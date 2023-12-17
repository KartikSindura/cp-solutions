#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    int count[t];
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        count[n - 1] = i + 1;
    }

    for (int i = 0; i < t; i++) {
        cout << count[i] << endl;
    }

    return 0;
}