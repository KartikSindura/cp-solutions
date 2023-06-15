#include <bits/stdc++.h>
using namespace std;

int main()
{
    // a 97
    string str;
    int fwd, bwd, temp, dist, count = 0;
    int ch = 97;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        fwd = abs(str[i] - ch);
        bwd = (26 - abs(str[i] - ch));
        ch = str[i+1];
        count += min(fwd, bwd);
    }
    cout << count;
}