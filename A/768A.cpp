#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    vector<int> arr;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        arr.push_back(n);
    }
    // sort(arr.begin(), arr.end());
    int smallest = *min_element(arr.begin(), arr.end());
    int largest = *max_element(arr.begin(), arr.end());
    int offset = 0;

    for (auto &val : arr) {
        if (val == smallest || val == largest) {
            offset++;
        }
    }
    cout << t - offset;

    return 0;
}