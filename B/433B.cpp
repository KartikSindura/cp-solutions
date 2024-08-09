#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
    int n;
    cin >> n;
    vector<ll> prefixsum(n + 1, 0);
    vector<ll> vec;
    vector<ll> org = vec;

    lp(i, n) {
        ll v;
        cin >> v;
        vec.push_back(v);
        prefixsum[i + 1] = prefixsum[i] + v;
    }

    vector<ll> sortedps = prefixsum;
    sort(vec.begin(), vec.end());
    lp(i, vec.size()) { sortedps[i + 1] = sortedps[i] + vec[i]; }

    int m;
    cin >> m;
    lp(i, m) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1) {
            cout << prefixsum[r] - prefixsum[l - 1] << endl;
        } else {
            cout << sortedps[r] - sortedps[l - 1] << endl;
        }
    }
}