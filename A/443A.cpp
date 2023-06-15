#include <bits/stdc++.h>
#include <set>
using namespace std;

int main() {
    
    string line;
    set<char> s;
    int count = 0;
    getline(cin , line);

    for (int i = 1; i < line.size()-1; i+= 3)
    {
        s.insert(line[i]);
    }
    cout << s.size();
    
}