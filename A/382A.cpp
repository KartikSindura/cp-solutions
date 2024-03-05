#include <bits/stdc++.h>
using namespace std;

int main() {
    string scale, str;
    cin >> scale >> str;
    int ind = scale.find('|'), left = ind, right = scale.size() - ind - 1;
    int count = 0;
    while (count < str.size()) {
        if (left <= right) {
            left++;
            scale = str[count] + scale;
            count++;
        } else {
            right++;
            scale = scale + str[count];
            count++;
        }
    }
    if (left == right) {
        cout << scale << endl;
    } else {
        cout << "Impossible";
    }
    return 0;
}