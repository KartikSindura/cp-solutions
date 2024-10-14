#include <bits/stdc++.h>
#include <queue>
#include <unordered_set>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

vector<int> dx = {2, 2, -2, -2, 1, -1, 1, -1};
vector<int> dy = {1, -1, 1, -1, 2, 2, -2, -2};

vector<string> generateStates(string move) {
  vector<string> states;
  lp(i, 8) {
    char na = char(move[0] + dx[i]);
    char nb = char(move[1] + dy[i]);
    if (na >= 'a' && na <= 'h' && nb >= '1' && nb <= '8') {
      string final = "";
      final += na;
      final += nb;
      states.push_back(final);
    }
  }
  return states;
}

int bfs(string start, string target) {
  if (start == target)
    return 0;
  int steps = 0;
  queue<string> q;
  unordered_set<string> visited;
  visited.insert(start);
  q.push(start);

  while (q.size() > 0) {
    int size = q.size();
    steps++;

    for (int i = 0; i < size; i++) {
      string store = q.front();
      q.pop();
      vector<string> states = generateStates(store);

      for (auto &val : states) {
        if (val == target) {
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

  string x, y;
  cin >> x >> y;
  int steps = bfs(x, y);
  cout << "To get from " << x << " to " << y << " takes " << steps
       << " knight moves.";
}
// e2 e4
// a1 b2
// b2 c3
// a1 h8
// a1 h7
// h8 a1
// b1 c3
// f6 f6
