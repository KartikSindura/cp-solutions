#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    multiset<int> m;
    int count_left = 0;
    int count_right = 0;
    bool check = true;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        m.insert(a);
    }
    for (auto &value: m) {
        if (check)
        {
            count_left += value;
            check = !check;
        } else {
            count_right += value;
            check  = !check;
        }
    }
    cout << count_left << " " << count_right;
    
}