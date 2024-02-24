#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[4] = {4, 2, 6, 8};
    int n;
    cin >> n;
    if (n == 1) {
        cout << 8;
    } else if (n == 2) {
        cout << 4;
    } else if (n == 0) {
        cout << 1;
    } else {
        cout << arr[((n + 2) % 4)];
    }
    return 0;
}