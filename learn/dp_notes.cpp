#include <iostream>
#include <vector>
using namespace std;
/*
 * min total cost for painting houses
 *
 * each house => (r, g, b)
 *
 * no two adjacent houses have same color
 *
 *
 * greedy will not work
 * why?
 *
 * (1, 100, 100) (1, 1000, 1000)
 * greedy = 1 + 1000
 * best = 100 + 1
 *
 * evaluate all states, pick the minimum one
 *
 * 3 houses
 * RGB => C1
 * RGR => C2
 * RBG => C3
 * RBR => C4
 * ...
 * ... => Cn
 *
 * Ans = min(C1, C2, ..., Cn)
 *
 * can you write a recursion to solve this?
 *
 * - find out cost of state
 * - comparing cost of all states
 *
 * 0 1 2 3 4 5 6
 * _ _ _ _ _ _ _ => filling slots
 *
 * _ _ _
 * R =>
 *      RB =>
 *            RBG => ?
 *            RBR => End
 *      RG =>
 *      RR X
 * G =>
 * B =>
 *
 * */

/*
 * _ _ _
 *
 * R ? ?
 * G ? ?
 * B ? ?
 *
 * _ _
 *
 * R ?
 * G ?
 * B ?
 *
 * i can fill current slot with R/G/B
 * for remaining slots, i dont know, fill whatever, just give me the minimum
 * answer
 *
 * f(0, R) = minimum cost for remaining slots if i fill R at slot 0
 *         = cost of putting R at 0 + min(f(1, G), f(1, B))
 *
 * f(1, G) = minimum cost for remaining slots if i fill G at slot 1
 *
 * ...
 *
 * f(N - 1, G) = minimum cost for remaining slots if i fill G at slot N-1 = ?
 *
 * R _ _ _ _ _ _ _ _
 * */

// 0 -> R
// 1 -> G
// 2 -> B
// int fillingSlots(int last, int currentSlot, int totalSlots, int costSoFar,
// vector<array<int, 3>> &costs) {
//   if (currentSlot < totalSlots) {
//     // fill this slot
//     if (last == 0) {
//       // fill G and B
//       int fillG = fillingSlots(last, currentSlot + 1, totalSlots, costSoFar +
//       costs[currentSlot][1], costs);
//     } else if (last == 1) {
//       // fill R and B
//     } else {
//       // fill G and R
//     }
//   } else {
//     return costSoFar;
//   }
// }

/*
 * _ _ _ _ _
 * G B R R B = Infinity
 * R G B R G = Some finite cost
 * R B G R G = Some finite cost
 *
 * minimum total cost?
 *
 * i will evaluate all costs, and find their minimum
 *
 * Caching?
 * (i, costSoFar, last, minimumTotalCost)
 * [25][20000][3][20000] = 75 * 4 * 10^8
 * */

void rec(int i, int n, int costSoFar, int last, int &minimumTotalCost,
         vector<vector<int>> &costs) {
  if (i == n) {
    // i have filled all slots
    minimumTotalCost = min(costSoFar, minimumTotalCost);
    return;
  }

  if (last != 0) { // it was not R
    // try R
    rec(i + 1, n, costSoFar + costs[i][0], 0, minimumTotalCost, costs);
  }

  if (last != 1) { // it was not G
    // try G
    rec(i + 1, n, costSoFar + costs[i][1], 1, minimumTotalCost, costs);
  }

  if (last != 2) { // it was not B
    // try B
    rec(i + 1, n, costSoFar + costs[i][2], 2, minimumTotalCost, costs);
  }
}

/*
 * _ _ _ ... 10^6
 * R B G => end reached => minimise this state's cost with global minima
 * G B G => end reached => minimise this state's cost with global minima
 *
 *
 * what is minimum total cost i can get, if i fill X at postion Y?
 *
 * f(0, R) => what is the minimum total cost i can get if i fill R at position 0
 *
 * f(0, R) = cost[0][R] + min(f(1, G), f(1, B))
 *
 * f(1, G) => what is min total cost i can get if i fill G at position 1
 *        = cost[1][G] + min(f(2, R), f(2, B))
 * f(1, B) => what is min total cost i can get if i fill B at position 1
 *        = cost[1][B] + min(f(2, R), f(2, G))
 *
 * f(2, R) = cost[2][R] + 0
 * f(2, G) = cost[2][G] + 0
 * f(2, B) = cost[2][B] + 0
 *
 * f(1, G) = cost[1][G] + min(cost[2][R], cost[2][B]) =
 * ..
 * ..
 *
 * f(0, R) => R _ _ _
 * f(0, G) => B _ _ _
 * f(0, B) => G _ _ _
 *
 * ans = min(f(0, R), f(0, G), f(0, B))
 *
 * _ _ _ _ _ => 3^N
 *
 * N = 10^5
 * 3^(10^5) == too much, it will not run in many many years
 *
 * After caching, what is time complexity?
 *
 * No of unique function calls * time per function call
 *
 * 25 * 3 * 1
 * O(N * 3)
 *
 * first time => evaluate everything
 * second time => O(1)
 * */

// Dyanmic Programming -> Caching
// cache this
// (i, currentValue)

int memo[25][3];
int solve(int i, int n, int currentValue, vector<vector<int>> &costs) {
  if (i == n) { // terminal state O(1)
    return 0;
  }

  if (memo[i][currentValue] != -1) {
    return memo[i][currentValue];
  }

  if (currentValue == 0) {
    memo[i][currentValue] =
        costs[i][0] + min(solve(i + 1, n, 1, costs), solve(i + 1, n, 2, costs));
  } else if (currentValue == 1) {
    memo[i][currentValue] =
        costs[i][1] + min(solve(i + 1, n, 0, costs), solve(i + 1, n, 2, costs));
  } else {
    memo[i][currentValue] =
        costs[i][2] + min(solve(i + 1, n, 0, costs), solve(i + 1, n, 1, costs));
  }

  return memo[i][currentValue];
}

int main() {
  int minimumTotalCost = INT_MAX;
  vector<vector<int>> costs = {
      {26, 40, 83},
      {49, 60, 57},
      {13, 89, 99},
  };
  int n = costs.size();
  rec(0, n, 0, -1, minimumTotalCost, costs);
  cout << minimumTotalCost << endl;

  memset(memo, -1, sizeof memo);

  int attemptTwo = min(min(solve(0, n, 0, costs), solve(0, n, 1, costs)),
                       solve(0, n, 2, costs));
  cout << attemptTwo << endl;
}

/*
 *
 *
 * [state behind you, some actions you have already taken] (params)
 * [some actions you can take now] (your choices, inside the function)
 * [some actions you will take later] (quantify it, return value) (min, max,
 * count)
 *
 * schedule - static
 *
 * params - current day, yesterday activity
 * choices - ependent on yesterday activity and current day schedule
 * quantify - quantify rest days and minimise it
 *
 * 0, 1, 2, 3, 4, 5, 6
 *
 * f(4, 0) = min rest days i can take between [4, 6] s.t. yesterday i did
 * activity 0
 *
 * f(currentDay, yesterdayActivity) = minimum number of rest days i can take
 * between [currentDay, N] such that yesterday i did yesterdayActivity
 *
 * f(currentDay, yesterdayActivity) = (based on current schedule and yesterday
 * activity)
 *
 *                                  rest = 1 + f(currentDay + 1, rest)
 *                                  gym = 0 + f(currentDay + 1, gym)
 *                                  code = 0 + f(currentDay + 1, code)
 *
 *                                  = min(rest, gym, code)
 *
 * f(N, yesterdayActivity) = 0
 *
 * f(N-1, yesterday) = 0/1 + f(N-1+1, rest / gym / code)
 * */
