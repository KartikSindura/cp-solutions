#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int n, m;
char boss;
// int visited[25][25];
char arr[100][100];
vector<bool> visited_char(26, false);
// vector<vector<int>> visited;
// vector<vector<char>> arr;

// unordered_set<char> visited_char;
const vector<int> dx = {0, 0, 1, -1};
const vector<int> dy = {1, -1, 0, 0};
int ans = 0;

bool is_valid(int x, int y, char c) {
    return x >= 0 && x < n && y >= 0 && y < m && c != '.' && c != boss &&
           !visited_char[c - 'A'];
}

void search(int x, int y) {
    // visited[x][y] = 1;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (is_valid(nx, ny, arr[nx][ny])) {
            // visited_char.insert(arr[nx][ny]);
            visited_char[arr[nx][ny] - 'A'] = true;
            ans++;
        }
    }
    arr[x][y] = '.';
}

int main() {
    cin >> n >> m >> boss;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // char l;
            // cin >> l;
            // arr[i][j] = l;
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == boss) {
                search(i, j);
            }
        }
    }

    cout << ans << endl;
}
