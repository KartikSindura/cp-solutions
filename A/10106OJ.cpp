#include <bits/stdc++.h>
using namespace std;

// string add(vector<string> vec) {}

int main() {
    string m1, m2;
    cin >> m1 >> m2;
    string str = "";
    string ans = "";
    reverse(m2.begin(), m2.end());
    reverse(m1.begin(), m1.end());
    string power_count = "";
    for (int i = 0; i < m2.size(); i++) {
        int carry = 0;
        for (int j = 0; j < m1.size(); j++) {
            int temp1 = m2[i] - '0';
            int temp2 = m1[j] - '0';
            int mul = (temp1 * temp2) + carry;
            if (j == m1.size() - 1) {
                str = to_string(mul) + str;
                continue;
            }
            if (mul > 9) {
                carry = (to_string(mul)[0]) - '0';
                str = to_string(mul)[1] + str;
            } else {
                str = to_string(mul) + str;
            }
        }
        ans += str + power_count + " ";
        str = "";
        power_count += "0";
    }
    cout << ans;
    return 0;
}