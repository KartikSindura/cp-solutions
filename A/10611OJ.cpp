#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)

int down(vector<int> &arr, int val) {
    int start = 0;
    int end = arr.size() - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] < val) {
            start = mid + 1;
        } else if (arr[mid] >= val) {
            end = mid - 1;
        }
    }
    if (end < 0) return -1;
    return arr[end];
}
int up(vector<int> &arr, int val) {
    int start = 0;
    int end = arr.size() - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] <= val) {
            start = mid + 1;
        } else if (arr[mid] > val) {
            end = mid - 1;
        }
    }
    if (end >= arr.size()) return -1;
    return arr[start];
}

int main() {
    vector<int> arr;
    vector<int> query;

    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    int q;
    cin >> q;
    while (q--) {
        int a;
        cin >> a;
        query.push_back(a);
    }
    for (auto &value : query) {
        int first = down(arr, value);
        int second = up(arr, value);
        if (first == -1) {
            cout << "X " << second << endl;
        } else if (second == -1) {
            cout << first << " X" << endl;
        } else {
            cout << first << " " << second << endl;
        }
    }

    return 0;
}
/*
4
1 4 5 7
4
4 6 8 10
*/