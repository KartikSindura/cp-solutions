#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

map<string, vector<string>> adj;
int steps = 0;

void dfs(string start, set<string> visited) {
  steps++;
  visited.insert(start);
  vector<string> des = adj[start];
  for (auto &val : des) {
    if (val == "BKK") {
      cout << "Found it!" << steps << endl;
      return;
    }

    if (visited.find(val) == visited.end()) {
      dfs(val, visited);
    }
  }
}

void bfs(string start) {
  set<string> visited = {start};
  queue<string> q;
  q.push(start);

  while (q.size() > 0) {
    string airport = q.front();
    q.pop();
    vector<string> des = adj[airport];

    for (auto &val : des) {
      if (val == "BKK") {
        cout << "Found it!" << endl;
      }

      if (visited.find(val) == visited.end()) {
        visited.insert(val);
        q.push(val);
        cout << val << endl;
      }
    }
  }
}

void addNode(string airport) { adj[airport] = {}; }

void addEdge(string destination, string source) {
  adj[source].push_back(destination);
  adj[destination].push_back(source);
}

int main() {
  vector<string> airports = {"PHX", "BKK", "OKC", "JFK", "LAX", "MEX",
                             "EZE", "HEL", "LOS", "LAP", "LIM"};
  multimap<string, string> routes = {
      {"PHX", "LAX"}, {"PHX", "JFK"}, {"JFK", "OKC"}, {"JFK", "HEL"},
      {"JFK", "LOS"}, {"MEX", "LAX"}, {"MEX", "BKK"}, {"MEX", "LIM"},
      {"MEX", "EZE"}, {"LIM", "BKK"},
  };

  for (auto &val : airports) {
    addNode(val);
  }
  for (auto &val : routes) {
    addEdge(val.first, val.second);
  }
  cout << "Adj list" << endl << endl;
  for (auto &val : adj) {
    cout << val.first << ": ";
    for (auto &dest : val.second) {
      cout << dest << " ";
    }
    cout << endl;
  }

  // bfs("PHX");
  set<string> visited;
  dfs("PHX", visited);
}
