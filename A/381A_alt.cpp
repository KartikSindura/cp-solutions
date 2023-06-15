#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> m;
    int n;
    cin >> n;
    int start = 0;
    int end = n - 1;
    pair<int, int> score = {0, 0};

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        m.push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        if ((m.at(start)) >= m.at(end))
        {
            score.first += m.at(start);
            start++;
        }
        else
        {
            score.first += m.at(end);
            end--;
        }
        swap(get<0>(score), get<1>(score));
    }
    if (n % 2 != 0)
    {
        swap(get<0>(score), get<1>(score));
    }
    cout << score.first << " " << score.second;
}