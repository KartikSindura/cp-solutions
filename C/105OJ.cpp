#include <bits/stdc++.h>
#include <iterator>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  int l, h, r;
  // vector<tuple<int, int, int>> buildings;
  vector<pair<int, int>> points;
  multiset<int> heights;
  heights.insert(0);
  vector<pair<int, int>> ans;

  int max_height = 0;
  while (cin >> l >> h >> r) {
    // buildings.push_back({l, h, r});
    points.push_back({l, -h});
    points.push_back({r, h});
  }
  // sort: first by x, then by height
  sort(points.begin(), points.end(),
       [](const pair<int, int> &a, const pair<int, int> &b) {
         if (a.first != b.first)
           return a.first < b.first;
         else
           return a.second < b.second;
       });

  for (pair<int, int> &val : points) {
    int x = val.first;
    int h = val.second;
    if (h < 0) {
      // start
      heights.insert(-h);
    } else {
      // end
      heights.erase(heights.find(h));
    }
    int curr_max = *heights.rbegin();
    if (curr_max != max_height) {
      ans.push_back({x, curr_max});
      max_height = curr_max;
    }
  }

  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i].first << " " << ans[i].second;
    if (i + 1 < ans.size())
      cout << " ";
  }
  cout << endl;
}

// Range overlap check => !(b<c || d<a)
// or cout << fixed << setprecision(int) << num;
// Look for monotonic behaviour -> binary search
// Condition for checking cliques -> edge != (1LL * vertex * (vertex - 1)) / 2
//
// Sample Input
// 1 11 5
// 2 6 7
// 3 13 9
// 12 7 16
// 14 3 25
// 19 18 22
// 23 13 29
// 24 4 28
// Sample Output
// 1 11 3 13 9 0 12 7 16 3 19 18 22 3 23 13 29 0
//
// 1 2 3 5 7 9 12 14 16 19 22 23 24 25 28 29
