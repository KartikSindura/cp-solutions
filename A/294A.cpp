#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, x, y;
    cin >> n;
    int birds[n];
    for (int i = 0; i < n; i++)
    {
        int birdie;
        cin >> birdie;
        birds[i] = birdie;
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        int right = birds[x - 1] - y;
        int left = y - 1;
        if (x - 2 >= 0)
            birds[x - 2] += left;
        if (x <= n - 1)
            birds[x] += right;
        birds[x - 1] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        cout << birds[i] << endl;
    }
}