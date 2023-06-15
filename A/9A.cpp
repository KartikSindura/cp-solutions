#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int hcf(int a, int b)
{
    int result = min(a, b);
    while (result > 0)
    {
        if (a % result == 0 && b % result == 0)
        {
            break;
        }
        result--;
    }
    return result;
}

int main()
{
    int a, b, count = 0;
    cin >> a >> b;
    int max_int = max(a, b);
    for (int i = 1; i <= 6; i++)
    {
        if (i >= max_int)
        {
            count++;
        }
    }
    if (max_int == 6)
    {
        count = 1;
    }
    
    int highest = hcf(count, 6);
    count /= highest;
    cout << count << "/" << 6 / highest;
}