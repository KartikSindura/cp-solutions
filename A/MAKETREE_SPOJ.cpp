#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < (int)(n); i++)
vector<vector<int>> arr;
vector<bool> vis;
vector<int> ans;

void dfs(int v) {
    vis[v] = true;
    for (auto &u : arr[v]) {
        if (!vis[u]) {
            dfs(u);
        }
    }
    ans.push_back(v);
}

int main() {
    int n, k;
    cin >> n >> k;
    arr = vector<vector<int>>(n + 1);
    vis = vector<bool>(n + 1);
    for (int i = 0; i < n; i++) {
        arr[i] = {};
    }
    for (int i = 0; i < k; i++) {
        int w;
        cin >> w;
        for (int j = 0; j < w; j++) {
            int adj;
            cin >> adj;
            arr[i].push_back(adj);
        }
    }

    vis.assign(n, false);
    ans.clear();
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    reverse(ans.begin(), ans.end());

    cout << endl;
    for (auto &value : ans) {
        cout << value << " ";
    }

    return 0;
}
/*
4 2
1 3
2 3 4

0: {3}
1: {3, 4}
2: {}
3: {}
*/