#include <bits/stdc++.h>
using namespace std;

int main() {
    int b, r, c = 10;
    cin >> b >> r;
    for (int i = 1; i < 10; i++)
    {
        if ((b*i)%10 == r || (b*i)%10 == 0)
        {
            c = i;
            break;
        }
    }
    cout << c;
    return 0;
}