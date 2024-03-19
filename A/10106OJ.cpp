#include <bits/stdc++.h>
using namespace std;

void add(string ans) {
    string zero = "0";
    stringstream iss(ans);
    string word;
    while (iss >> word) {
        if (zero == "0") {
            zero = word;
        } else {
            int zero_count = zero.size() - 1;
            int new_word_count = word.size() - 1;
            int mini = min(zero_count, new_word_count);
            string replace;
            int carry = 0;
            for (int i = 0; i <= mini; i++) {
                int num = ((zero[zero_count] - '0') +
                           (word[new_word_count] - '0') + carry);
                if (num > 9) {
                    carry = (to_string(num)[0]) - '0';
                    replace = to_string(num)[1] + replace;
                    zero_count--;
                    new_word_count--;
                } else {
                    replace = to_string(num) + replace;
                    carry = 0;
                    zero_count--;
                    new_word_count--;
                }
            }
            string sub = word.substr(0, max(word.size(), zero.size()) -
                                            min(word.size(), zero.size()));
            if (carry > 0) {
                int changes = stoi(sub) + carry;
                replace = to_string(changes) + replace;
                zero = replace;
            } else {
                replace = sub + replace;
                zero = replace;
            }
        }
    }
    cout << zero;
}

int main() {
    string m1, m2;
    while (cin >> m1 >> m2) {
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
                    carry = 0;
                }
            }
            ans += str + power_count + " ";
            str = "";
            power_count += "0";
        }
        add(ans);
    }
    return 0;
}