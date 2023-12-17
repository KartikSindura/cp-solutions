#include <bits/stdc++.h>
using namespace std;

int main() {
    int count[4] = {0};
    int arr[4][5001];
    int t, n;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> n;
        count[n]++;
        arr[n][count[n]] = i;
    }

    int nteam = min(min(count[1], count[2]), count[3]);
    cout << nteam << endl;
    for (int i = 1; i <= nteam; i++) {
        cout << arr[1][i] << " " << arr[2][i] << " " << arr[3][i] << " "
             << endl;
    }
}
