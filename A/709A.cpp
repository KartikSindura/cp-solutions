#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, b, d, count = 0, waste_count = 0;
    int ele;
    cin >> n >> b >> d;
    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        if (ele <= b)
        {
            count += ele;
        }
        if (count > d)
        {
            waste_count++;
            count = 0;  
        }
    }

    cout << waste_count;
}