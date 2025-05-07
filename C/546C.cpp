#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int versus(int a, int b) {
  if (a > b) {
    return 0;
  }
  return 1;
}

int main() {
  int n;
  cin >> n;

  int k1;
  cin >> k1;
  deque<int> p;
  lp(i, k1) {
    int x;
    cin >> x;
    p.push_back(x);
  }

  int k2;
  cin >> k2;
  deque<int> q;
  lp(i, k2) {
    int x;
    cin >> x;
    q.push_back(x);
  }

  set<pair<deque<int>, deque<int>>> game_states;
  int games = 0;
  int finalWinner = 0;
  while (!p.empty() && !q.empty()) {
    if (game_states.find({p, q}) != game_states.end()) {
      cout << -1 << endl;
      return 0;
    }
    game_states.insert({p, q});
    int a = p.front();
    int b = q.front();
    p.pop_front();
    q.pop_front();
    int winner = versus(a, b);
    if (winner == 0) {
      // player 1 wins
      p.push_back(b);
      p.push_back(a);
    } else {
      // player 2 wins
      q.push_back(a);
      q.push_back(b);
    }
    games++;
    finalWinner = winner;
  }
  cout << games << " " << finalWinner + 1 << endl;
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
