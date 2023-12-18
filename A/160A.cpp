#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, count = 0, amount = 0, sum = 0;
    cin >> t;
    vector<int> vec;
    while (t--) {
        int n;
        cin >> n;
        vec.push_back(n);
        sum += n;
    }
    sort(vec.begin(), vec.end());

    for (int i = 0; i <= vec.size(); i++) {
        amount += vec.back();
        sum -= vec.back();
        vec.pop_back();
        count++;
        if (amount > sum) {
            break;
        }
    }
    cout << count;

    return 0;
}