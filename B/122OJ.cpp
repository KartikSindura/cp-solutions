#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

struct TreeNode {
  int val;
  bool has_val;
  TreeNode *left, *right;
  TreeNode() : val(0), has_val(false), left(nullptr), right(nullptr) {}
};

bool add_node(TreeNode *&root, int val, string path) {
  if (!root) {
    root = new TreeNode();
  }
  TreeNode *cur = root;
  for (char c : path) {
    if (c == 'L') {
      if (!cur->left) {
        cur->left = new TreeNode();
      }
      cur = cur->left;
    } else if (c == 'R') {
      if (!cur->right) {
        cur->right = new TreeNode();
      }
      cur = cur->right;
    }
  }
  if (cur->has_val) {
    // duplicate value
    return false;
  }
  // update the value to the cur node
  cur->val = val;
  cur->has_val = true;
  return true;
}

bool bfs(TreeNode *&root, vector<int> &result) {
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode *front = q.front();
    q.pop();

    if (!front->has_val) {
      return false;
    }
    result.push_back(front->val);
    if (front->left) {
      q.push(front->left);
    }

    if (front->right) {
      q.push(front->right);
    }
  }
  return true;
}

void free_tree(TreeNode *root) {
  if (!root) {
    return;
  }
  free_tree(root->left);
  free_tree(root->right);
  delete root;
}

int main() {
  string node;
  TreeNode *root = nullptr;
  bool valid = true;

  while (cin >> node) {
    if (node == "()") {
      vector<int> result;
      if (!valid || !bfs(root, result)) {
        cout << "not complete" << endl;
      } else {
        for (int i = 0; i < result.size(); ++i) {
          if (i)
            cout << " ";
          cout << result[i];
        }
        cout << endl;
      }
      free_tree(root);
      root = nullptr;
      valid = true;
    } else {
      int val;
      string path;
      int comma = node.find(',');
      val = stoi(node.substr(1, comma));
      path = node.substr(comma + 1, node.length() - 1);
      if (!add_node(root, val, path)) {
        valid = false;
      }
    }
  }
}

// Think on paper, not on code.
// Read problem statement twice.
// Think pictorially.

// Range overlap check => !(b<c || d<a)
// cout << setprecision(int);
// cout << num;
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
