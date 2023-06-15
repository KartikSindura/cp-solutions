#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    int a, count = 0;
    string str;
    for (int i = 0; i < 4; i++)
    {
        cin >> a;
        v.push_back(a);
    }
    cin >> str;
    for (int i = 0; i < str.length(); i++) count += v[(str[i] - '0')-1];
    cout << count<<endl;
}