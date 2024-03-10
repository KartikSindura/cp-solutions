#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    int count = 1;
    while (n != 1) {
        if (n % 2 != 0) {
            count++;
            n /= 2;
        } else {
            n /= 2;
        }
    }
    cout << count;
}