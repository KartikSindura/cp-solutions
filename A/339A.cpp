#include <bits/stdc++.h>

#include <set>
#include <sstream>
using namespace std;
int main() {
    string s, ans;
    cin >> s;
    multiset<string> m;

    stringstream ss(s);
    string word;
    while (!ss.eof()) {
        getline(ss, word, '+');
        m.insert(word);
    }
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        ans += *iter + '+';
    }
    cout << ans.substr(0, ans.size() - 1);
}