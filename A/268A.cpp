#include <bits/stdc++.h>
using namespace std;

int main()
{

    int a, h, n, count = 0;
    cin >> n;
    map<int, pair<int, int>> teams;
    for (int i = 0; i < n; i++)
    {
        cin >> h >> a;
        teams.insert({i, {h, a}});
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (teams[i].first == teams[j].second)
            {
                count++;
            }
            if (teams[i].second == teams[j].first){
                count++;
            }
        }
    }
    cout << count;
}