#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    string delimiter = "WUB";
    string ans;

    size_t pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        if (token != "") {
            ans += token + " ";
        }
        s.erase(0, pos + delimiter.length());
    }
    if (!s.empty()) {
        ans += s;
    }
    cout << ans << endl;
    return 0;
}