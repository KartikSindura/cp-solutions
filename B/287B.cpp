#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)

int main() {
    int n, k, count = 0, jars = 0, ans = -1;
    cin >> n >> k;
    if (k >= n) {
        ans = 1;
    } else if (k < n) {
        for (int i = k; i >= 2; i--) {
            count += i;
            jars++;
            if (count >= n) {
                ans = jars;
                break;
            } else {
                count--;
            }
        }
    }
    if (ans) {
        cout << ans;
    } else {
        cout << ans;
    }

    return 0;
}

/*
8 4
4+3+2-2
4 1
3 1
3+3 2
3+3-1 2
3+3-1+2 3

4 3
3+2-1

8 4
4+3+2-2


*/
