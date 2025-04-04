#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

ll l, r;
int n, x;
vector<int> prob;
map<tuple<int, long long, int, int, int>, int> dp;
int solve(int i, ll total, vector<int> &prob, int count, int madiff,
          int mdiff) {
  if (i == n) {
    if (count >= 2 && total >= l && total <= r && (madiff - mdiff) >= x) {
      return 1;
    }
    return 0;
  }

  if (i == n) {
    return 0;
  }

  tuple<int, long long, int, int, int> state = {i, total, mdiff, madiff, count};
  if (dp.count(state))
    return dp[state];

  int total_ways = 0;
  // take
  int take = solve(i + 1, total + prob[i], prob, count + 1,
                   max(prob[i], madiff), min(prob[i], mdiff));

  total_ways += take;
  // skip
  int skip = solve(i + 1, total, prob, count, madiff, mdiff);
  total_ways += skip;

  return dp[state] = total_ways;
}

int main() {
  cin >> n >> l >> r >> x;
  prob.resize(n);
  lp(i, n) { cin >> prob[i]; }
  cout << solve(0, 0, prob, 0, 0, 1e6);
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
