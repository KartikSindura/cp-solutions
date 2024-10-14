#include <iostream>
#include <queue>
#include <unordered_set>
#include <utility>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

bool isWinner(const string &board, char player) {
  vector<vector<int>> winningCombos = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8},
                                       {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
                                       {0, 4, 8}, {2, 4, 6}};
  for (const auto &combo : winningCombos) {
    if (board[combo[0]] == player && board[combo[1]] == player &&
        board[combo[2]] == player) {
      return true;
    }
  }
  return false;
}

bool isValidCount(const string &board) {
  int xCount = 0, oCount = 0;
  for (char c : board) {
    if (c == 'X')
      xCount++;
    else if (c == 'O')
      oCount++;
  }
  return (xCount == oCount || xCount == oCount + 1);
}

bool bfs(string target) {
  if (!isValidCount(target))
    return false;
  string board = ".........";
  unordered_set<string> visited;
  visited.insert(board);
  queue<pair<string, char>> q;
  q.push({board, 'X'});

  while (q.size() > 0) {
    auto [curBoard, curPlayer] = q.front();
    q.pop();

    if (curBoard == target) {
      return true;
    }

    if (isWinner(curBoard, 'X') == true || isWinner(curBoard, 'O')) {
      continue;
    }

    lp(i, 9) {
      if (curBoard[i] == '.') {
        string newBoard = curBoard;
        newBoard[i] = curPlayer;
        char nextPlayer = (curPlayer == 'X' ? 'O' : 'X');

        if (visited.find(newBoard) == visited.end()) {
          visited.insert(newBoard);
          q.push({newBoard, nextPlayer});
        }
      }
    }
  }
  return false;
}

int main() {
  string board;
  while ((cin >> board)) {
    if (board == "end") {
      break;
    }
    if (bfs(board)) {
      cout << "valid" << endl;
    } else {
      cout << "invalid" << endl;
    }
  }
}

// Input:
// XXXOO.XXX
// XOXOXOXOX
// OXOXOXOXO
// XXOOOXXOX
// XO.OX...X
// .XXX.XOOO
// OOXXXOOXO
// end
//
// Output:
// invalid
// valid
// invalid
// valid
// valid
// invalid
// invalid
//
