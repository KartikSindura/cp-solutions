#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> vec;
    vector<int> prefixSum;
    ll count = 0;
    lp(i, n) {
        int h;
        cin >> h;
        count += h;
        vec.push_back(h);
        prefixSum.push_back(count);
    }

    pair<int, int> mini = {prefixSum[k - 1], 1};
    for (int i = k; i < n; i++) {
        if ((prefixSum[i] - prefixSum[i - k]) < mini.first) {
            mini = {(prefixSum[i] - prefixSum[i - k]), i - k + 2};
        }
    }
    cout << mini.second;
}

// 1 2 6 1 1 7 1
// 1 3 9 10 11 18 19