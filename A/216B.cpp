#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> arr;
vector<int> vis;

enum status { PATH = 0, CYCLE = 1 };

status dfs(int cur, int par, int &count) {
    if (vis[cur]) {
        return CYCLE;
    }
    vis[cur] = 1;
    for (auto &child : arr[cur]) {
        if (child != par) {
            ++count;
            if (dfs(child, cur, count) == CYCLE) {
                return CYCLE;
            }
        }
    }
    return PATH;
}

int main() {
    int n, p;
    cin >> n >> p;
    arr = vector<vector<int>>(n);
    vis = vector<int>(n);

    for (int i = 0; i < p; i++) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    int toRemove = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            int count = 0;
            status ans = dfs(i, -1, count);
            if (ans == CYCLE) {
                toRemove += (count % 2 == 1);
            }
        }
    }
    if ((n - toRemove) % 2 == 1) {
        toRemove++;
    }
    cout << toRemove;

    return 0;
}
/*
6 6
1 2
2 3
3 1
4 5
5 6
6 4
[1]:[2]
[2]:[1, 3]
[3]:[2, 1]
[4]:[5, 6]
[5]:[4, 6]
[6]:[4, 5]
*/