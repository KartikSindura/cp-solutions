    #include <bits/stdc++.h>
    using namespace std;
    // 900000000000000009 900000000000000029 -> 900000000000000009
    // 900000000000000010 900000000000000021 2 4 -> 2 3 4

    bool isCoprime(long long i, long long j) {
        if (gcd(i, j) == 1) {
            return true;
        }
        return false;
    }
    long long check(long long l, long long r) {
        long long i = l + 1;
        while (i < r) {
            if (isCoprime(l, i) && isCoprime(i, r)) {
                return i;
            }
            i++;
        }
        return -1;
    }

    int main() {
        long long l, r;
        cin >> l >> r;
        int found = 0;

        // cout << l << r
        for (int i = 0; i < r - l; i++) {
            if (!isCoprime(l, r)) {
                long long checked = check(l, r);
                if (checked != -1) {
                    cout << l << " " << checked << " " << r;
                    found = 1;
                    break;
                } else {
                    r--;
                }
            } else {
                r--;
            }
        }
        if (found == 0) {
            cout << -1;
        }
        cout << isCoprime(640097987171091791, 640097987171091833);
        return 0;
    }