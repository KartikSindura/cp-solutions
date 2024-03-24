#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char arr[9][9];
const vector<int> dx = {0, 0, -1};
const vector<int> dy = {1, -1, 0};
const vector<string> dir = {"right", "left", "forth"};
// IEHOVA
string ans = "";
string word = "IEHOVA#";

bool valid(int i, int j, int n, int m, int count) {
    return i < m && i >= 0 && j < n && j >= 0 && arr[i][j] == word[count];
}

void dfs(int i, int j, int n, int m, int count) {
    for (int k = 0; k < 3; k++) {
        int ni = i + dx[k], nj = j + dy[k];
        if (valid(ni, nj, n, m, count)) {
            count++;
            ans += dir[k] + " ";
            dfs(ni, nj, n, m, count);
        }
    }
}

int main() {
    // string word = "IEHOVA#";
    int count = 0;
    int t;
    cin >> t;
    while (t--) {
        ans = "";
        memset(arr, '0', sizeof(arr));
        int m, n;
        cin >> m >> n;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }
        for (int j = 0; j < n; j++) {
            if (arr[m - 1][j] == '@') {
                dfs(m - 1, j, n, m, count);
            }
        }
        cout << ans.substr(0, ans.size() - 1) << endl;
    }
    return 0;
}
/*
2
6 5
PST#T
BTJAS
TYCVM
YEHOF
XIBKU
N@RJB
5 4
JA#X
JVBN
XOHD
DQEM
T@IY
*/
