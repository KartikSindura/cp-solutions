#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
int n;

int valid(int p) {
    if (p < 0 || p >= n) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    int a;
    cin >> n >> a;
    vector<int> vec;
    lp(i, n) {
        int p;
        cin >> p;
        vec.push_back(p);
    }

    int count = 0;
    if (vec[a - 1] == 1) {
        count++;
    }
    for (int i = 1; i < n; i++) {
        if ((!valid(a - i - 1) && (valid(a + i - 1) && vec[a + i - 1] == 1)) ||
            (!valid(a + i - 1) && (valid(a - i - 1) && vec[a - i - 1] == 1))) {
            count++;
        } else if ((valid(a - i - 1) && vec[a - i - 1] == 1) &&
                   (valid(a + i - 1) && vec[a + i - 1] == 1)) {
            count += 2;
        }
    }
    cout << count;
    return 0;
}
/*
6 3
1 1 1 0 1 0
5 2
0 0 0 1 0

1 1 && 1 1 sure +2
0 1 && 1 1 sure +1
1 0 && 1 1 not sure

*/