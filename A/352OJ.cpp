#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int visited[25][25];
char arr[25][25];

void dfs(int x, int y, int n, int m) {
    vector<pair<int, int>> vec = find_neighbors(x, y, n, m);
    visited[x][y] = 1;
    for (auto &value : vec) {
        if (!visited[value.first][value.second] &&
            arr[value.first][value.second] == '1') {
            dfs(value.first, value.second, n, m);
        }
    }
}

const vector<int> dx = {0, 0, 1, -1, 1, -1, 1, -1};
const vector<int> dy = {1, -1, 0, 0, 1, -1, -1, 1};

bool is_valid (int x, int y, int n, int m) {
    // 1. Check if index is within bounds
    // 2. check your visited
    // 3. check any other remaining conditions
    return x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && arr[x][y] == '1';
}

void dfs_better(int x, int y, int n, int m) {
    cout << "dfs_better " << x << ", " << y << endl;
    /*
           (y)
            0 1 2
      (x) 0 a b c
          1 d e f
          2 g h x

    e -> a, b, c, d, f, g, h, x -> 4 sides + 4 diagonals
    e -> b, d, f, h -> 4 sides
    e -> a, c, g, x -> 4 diagonals
    
    e -> b, d, f, h -> 4 sides

    (1, 1) -> (0, 1), (1, 0), (1, 2), (2, 1)
    (x, y) -> (x - 1, y) [UP], (x + 1, y) [DOWN], (x, y + 1) [RIGHT], (x, y - 1) [LEFT]
    offset (k) = 1
    
    List of offsets = {
        (-1, 0),
        (1, 0),
        (0, 1),
        (0, -1)
    }

    For 8 directions

    int dx[] = {0, 0, 1, -1, 1, -1, 1, -1}
    int dy[] = {1, -1, 0, 0, 1, -1, -1, 1}
    */

    visited[x][y] = 1;
    for (int k = 0; k < 8; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        // check if this is valid (nx, ny)
        if (is_valid(nx, ny, n, m)) {
            dfs_better(nx, ny, n, m);
        }
    }
}

int main() {
    string line;
    fstream file("pixels.txt");
    while (!file.eof()) {
        getline(file, line);
        int n = stoi(line);
        int m;
        int ans = 0;
        memset(visited, 0, sizeof(visited));
        memset(arr, '0', sizeof(arr));
        for (int x = 0; x < n; x++) {
            string str;
            getline(file, str);
            m = str.size();
            for (int y = 0; y < str.size(); y++) {
                arr[x][y] = str[y];
            }
        }
        for (int x = 0; x < n; x++) {
            cout << endl;
            for (int y = 0; y < m; y++) {
                cout << arr[x][y];
                if (arr[x][y] == '1' && visited[x][y] == 0) {
                    ans += 1;
                    dfs_better(x, y, n, m);
                }
            }
        }
        cout << endl << "ans: " << ans;
    }
    file.close();

    return 0;
}