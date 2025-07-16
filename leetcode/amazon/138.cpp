#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
public:
  Node *copyRandomList(Node *head) {
    if (!head)
      return nullptr;

    Node *curr = head;
    unordered_map<Node *, Node *> nodeMap;
    while (curr) {
      nodeMap[curr] = new Node(curr->val);
      curr = curr->next;
    }
    curr = head;
    while (curr) {
      if (curr->next) {
        nodeMap[curr]->next = nodeMap[curr->next];
      }
      if (curr->random) {
        nodeMap[curr]->random = nodeMap[curr->random];
      }
      curr = curr->next;
    }
    return nodeMap[head];
  }
};
// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
