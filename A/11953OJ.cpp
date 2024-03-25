// #include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

char arr[100][100];
int visited[100][100];
const vector<int> dx = {0, 0, -1, 1};
const vector<int> dy = {1, -1, 0, 0};

bool valid(int i, int j, int n, int len) {
    return i < n && i >= 0 && j < n && j >= 0 &&
           (arr[i][j] == 'x' || arr[i][j] == '@') && !visited[i][j];
}

void dfs(int i, int j, int n, int len) {
    visited[i][j] = 1;
    // for (int i = 0; i < n; i++) {
    //     cout << endl;
    //     for (int k = 0; k < n; k++) {
    //         cout << visited[i][k];
    //     }
    // }
    // cout << endl << "length: " << len << endl;
    for (int k = 0; k < 4; k++) {
        int ni = i + dx[k], nj = j + dy[k];
        if (valid(ni, nj, n, len) && len < n / 2) {
            len++;
            dfs(ni, nj, n, len);
        }
    }
}

int main() {
    int t;
    cin >> t;
    int temp = 1;
    while (t--) {
        int n, count = 0;
        cin >> n;
        memset(visited, 0, sizeof(visited));
        memset(arr, '.', sizeof(arr));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == 'x' && visited[i][j] == 0) {
                    int len = 1;
                    dfs(i, j, n, len);
                    count++;
                }
            }
        }
        cout << "Case " << temp << ": " << count << endl;
        temp++;
    }
}
/*
2
4
x...
..x.
@.@.
....
2
..
x.

*/
