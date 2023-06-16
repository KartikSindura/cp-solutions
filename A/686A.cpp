#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long int x;
    cin >> n >> x;
    int dist = 0;
    char sign;
    long long int num;
    while (n--) {
        cin >> sign >> num;
        if (sign == '+') {
            x += num;
        } else if (num <= x) {
            x -= num;
        } else {
            dist++;
        }
    }
    cout << x << " " << dist;
}