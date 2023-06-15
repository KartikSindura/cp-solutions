#include <bits/stdc++.h>
using namespace std;

int main() {
    string t, c;
    int count = 0;
    cin >> t >> c;
    for (int i = 0; i < c.length(); i++)
    {
        if (c[i] == t[count])
        {
            count++;
        }
    }
    cout << count+1; 
}