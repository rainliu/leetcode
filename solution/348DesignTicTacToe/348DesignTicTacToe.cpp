#include <vector>
using namespace std;

class TicTacToe {
private:
  vector<int> h[2], v[2];
  int d[2][2];

public:
  /** Initialize your data structure here. */
  TicTacToe(int n) {
    d[0][0] = d[1][0] = d[0][1] = d[1][1] = 0;
    for (int i = 0; i < n; i++) {
      h[0].push_back(0);
      h[1].push_back(0);
      v[0].push_back(0);
      v[1].push_back(0);
    }
  }

  /** Player {player} makes a move at ({row}, {col}).
      @param row The row of the board.
      @param col The column of the board.
      @param player The player, can be either 1 or 2.
      @return The current winning condition, can be either:
              0: No one wins.
              1: Player 1 wins.
              2: Player 2 wins. */
  int move(int row, int col, int player) {
    int n = h[0].size();
    if (row == col) {
      d[player - 1][0]++;
    }
    if (row == n - 1 - col) {
      d[player - 1][1]++;
    }
    h[player - 1][row]++;
    v[player - 1][col]++;

    for (int p = 0; p < 2; p++) {
      if (d[p][0] == n) {
        return p + 1;
      }
      if (d[p][1] == n) {
        return p + 1;
      }
      for (int k = 0; k < n; k++) {
        if (h[p][k] == n) {
          return p + 1;
        }
        if (v[p][k] == n) {
          return p + 1;
        }
      }
    }
    return 0;
  }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */

int main() { return 0; }