#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
    int n;
    cin >> n;
    vector<ll> vec;
    lp(i, n) {
        ll a;
        cin >> a;
        vec.push_back(a);
    }

    int left = 0;
    for (int i = 0; i < n - 1; i++) {
        if (vec[i] > vec[i + 1]) {
            left = i;
            break;
        }
    }
    int right = left + 1;
    for (int i = right; i < n - 1; i++) {
        if (vec[i] < vec[i + 1]) {
            right = i;
            break;
        }
        right++;
    }

    cout << left+1 << " " << right+1;
}

// 3 4 7 6 5 8