#include <bits/stdc++.h>
using namespace std;

int main()
{
    float n, k, t, d;
    cin >> n >> t >> k >> d;
    float cakes_per_min = t / k;
    float time_without_oven = ceil(n / k) * t;

    if (time_without_oven < d || time_without_oven <= t)
    {
        cout << "NO";
    }
    else if (t > d)
    {
        cout << "YES";
    }
    else
    {
        float cakes_in_building_time = floor(d / t) * k;
        float cakes_left = n - cakes_in_building_time;
        float t2 = d + ceil(cakes_left / (k * 2)) * t;

        if (time_without_oven > (t2))
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
    }
}