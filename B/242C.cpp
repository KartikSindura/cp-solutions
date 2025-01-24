#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

map<ll, pair<ll, ll>> allowed;
vector<int> dx = {1, -1, 0, 0, 1, -1, 1, -1};
vector<int> dy = {0, 0, -1, 1, -1, -1, 1, 1};

struct pair_hash {
  template <class T1, class T2> size_t operator()(const pair<T1, T2> &p) const {
    return hash<T1>()(p.first) ^ hash<T2>()(p.second);
  }
};

bool checkValid(ll a, ll b) {
  if (allowed.find(a) != allowed.end()) {
    pair<ll, ll> ginku = allowed[a];
    if (b >= ginku.first && b <= ginku.second) {
      return true;
    }
  }
  return false;
}

vector<pair<ll, ll>> generateStates(ll x0, ll x1) {
  vector<pair<ll, ll>> states;
  lp(i, 8) {
    ll nx0 = x0 + dx[i];
    ll nx1 = x1 + dy[i];
    if (checkValid(nx0, nx1)) {
      states.push_back({nx0, nx1});
    }
  }
  return states;
}

ll bfs(ll x0, ll x1, ll y0, ll y1) {
  if (x0 == y0 && x1 == y1)
    return 0;

  ll steps = 0;
  unordered_set<pair<ll, ll>, pair_hash> visited;
  queue<pair<ll, ll>> q;

  q.push({x0, x1});
  visited.insert({x0, x1});

  while (!q.empty()) {
    ll size = q.size();
    steps++;

    while (size--) {
      pair<ll, ll> store = q.front();
      q.pop();

      vector<pair<ll, ll>> states = generateStates(store.first, store.second);

      for (auto &val : states) {
        if (val.first == y0 && val.second == y1) {
          return steps;
        }

        if (visited.find(val) == visited.end()) {
          visited.insert(val);
          q.push(val);
        }
      }
    }
  }
  return -1;
}

int main() {
  ll x0, x1, y0, y1;
  cin >> x0 >> x1 >> y0 >> y1;
  int n;
  cin >> n;

  lp(i, n) {
    ll r, a, b;
    cin >> r >> a >> b;
    // allowed.push_back({r, a, b});
    allowed[r] = {a, b};
  }

  ll result = bfs(x0, x1, y0, y1);
  cout << result << endl;
}
