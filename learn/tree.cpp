#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

struct node {
  int data;
  node *left;
  node *right;

  node(int val) {
    data = val;
    left = right = nullptr;
  }
};

int main() {
  node *root = new node(10);
  root->left = new node(5);
  root->right = new node(15);
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
