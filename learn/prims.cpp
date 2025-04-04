#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
 * Priority queue (start, end, cost)
 * Iterate over all outgoing edges and add them to priority queue
 * Look into the priority queue and pull the next most promising edge which is
 * the lowest value of cost is added to MST, this also means we process that
 * node Next, iterate over all the edges of the selected node and add them to
 * priority queue Do not add already visited edges into the priority queue
 *
 *
 * what we need:
 * n = number of nodes in graph
 * pq = priority queue data structure consiting of {start node, end node, cost
 * of the edge} tuples, sorts edges by minimum cost g = graph representing and
 * adjacency list
 * visited = {false, false, ...}
 * g = graph
 */

int n, m;
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>>
    pq;
vector<bool> visited;
vector<vector<pair<int, int>>> g;

void addEdges(int nodeIndex) {
  visited[nodeIndex] = true;

  for (auto &[neighbor, cost] : g[nodeIndex]) {
    if (!visited[neighbor]) {
      pq.push(make_tuple(cost, nodeIndex, neighbor));
    }
  }
}

tuple<vector<tuple<int, int, int>>, int> lazyPrims(int start = 0) {
  int edgeCount = 0, mstCost = 0;
  vector<tuple<int, int, int>> mstEdges;

  addEdges(start);

  while (!pq.empty() && edgeCount < n - 1) {
    auto [cost, from, to] = pq.top();
    pq.pop();

    if (visited[to])
      continue;

    mstEdges.push_back({from, to, cost});
    mstCost += cost;
    edgeCount++;

    addEdges(to);
  }

  if (edgeCount != n - 1)
    return {{}, -1}; // No valid MST exists
  return {mstEdges, mstCost};
}

int main() {
  cin >> n >> m;
  g.assign(n, vector<pair<int, int>>());
  visited.assign(n, false);

  for (int i = 0; i < m; i++) {
    int u, v, cost;
    cin >> u >> v >> cost;
    g[u].push_back({v, cost});
    g[v].push_back({u, cost});
  }

  auto [mstEdges, mstCost] = lazyPrims(0);

  if (mstCost == -1) {
    cout << "No MST exists\n";
  } else {
    cout << "MST Cost: " << mstCost << "\nEdges in MST:\n";
    for (auto &[u, v, cost] : mstEdges) {
      cout << u << " - " << v << " (Cost: " << cost << ")\n";
    }
  }
}

// 5 6
// 0 1 2
// 0 3 6
// 1 2 3
// 1 3 8
// 1 4 5
// 2 4 7
