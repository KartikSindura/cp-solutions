#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, crime_count = 0, o = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        if (c < 0)
        {
            if (o > 0)
            {
                o--;
            } else {
                crime_count++;
            }
            
        } else {
            o += c;
        }
        
    }
    cout << crime_count;
}