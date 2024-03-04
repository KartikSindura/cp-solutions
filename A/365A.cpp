#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int count = 0;
    string main = "0123456789";
    while (n--) {
        string s;
        cin >> s;
        int check = 0;
        for (int i = 0; i <= k; i++)
        {
            if (s.find(main[i]) != -1) {
                check++;
            }
        }
        if (check >= k+1) {
            count++;
        }
    }
    cout << count;
    return 0;
}