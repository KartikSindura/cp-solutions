#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[100];
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    bool valid = true;
    for (int i = 0; i < n; i++) {
        int c = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                ++c;
            }
        }
        if (n < 2 * c - 1) {
            valid = false;
            break;
        }
    }

    if (valid) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}