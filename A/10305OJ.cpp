#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)

vector<vector<int>> adj(150);
int vis[150];
vector<int> ans;

void dfs(int i) {
    vis[i] = 1;
    for (auto &value : adj[i]) {
        if (!vis[value]) {
            dfs(value);
        }
    }
    ans.push_back(i + 1);
}

int main() {
    int n, k;
    while (cin >> n >> k, n && k) {
        adj.clear();
        ans.clear();
        memset(vis, 0, sizeof(vis));
        adj = vector<vector<int>>(n);
        // vis = vector<int>(n);

        for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;
            adj[a - 1].push_back(b - 1);
        }
        // vis.assign(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i);
            }
        }
        reverse(ans.begin(), ans.end());

        for (int i = 0; i < ans.size(); i++) {
            if (i == ans.size() - 1) {
                cout << ans[i];
            } else {
                cout << ans[i] << " ";
            }
        }
    }

    return 0;
}
/*
5 4
1 2
2 3
1 3
1 5
0 0

*/