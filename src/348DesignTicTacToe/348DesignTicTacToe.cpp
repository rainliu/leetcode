class TicTacToe {
    vector<int> rows, cols;
    int diagonal, antidiagonal;
    int n;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        rows.resize(n, numeric_limits<int>::max());
        cols.resize(n, numeric_limits<int>::max());
        diagonal = numeric_limits<int>::max();
        antidiagonal = numeric_limits<int>::max();
        this->n = n;
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
        if(rows[row]==numeric_limits<int>::max()){
            rows[row] = player == 1 ? 1:-1;
        }else if( (rows[row]>0&&player==1) || 
                  (rows[row]<0&&player==2) ){
            rows[row] += player == 1 ? 1:-1;
            if(rows[row]==n || rows[row]==-n){
                return player;
            }
        }else{
            rows[row] = 0;
        }
        
        if(cols[col]==numeric_limits<int>::max()){
            cols[col] = player == 1 ? 1:-1;
        }else if( (cols[col]>0&&player==1) || 
                  (cols[col]<0&&player==2) ){
            cols[col] += player == 1 ? 1:-1;
            if(cols[col]==n || cols[col]==-n){
                return player;
            }
        }else{
            cols[col] = 0;
        }
        
    
        if(row==col){
            if(diagonal==numeric_limits<int>::max()){
                diagonal = player == 1 ? 1:-1;
            }else if( (diagonal>0&&player==1) || 
                      (diagonal<0&&player==2) ){
                diagonal += player == 1 ? 1:-1;
                if(diagonal==n || diagonal==-n){
                    return player;
                }
            }else{
                diagonal = 0;
            }
        }
        
        if(n-1-row==col){
            if(antidiagonal==numeric_limits<int>::max()){
                antidiagonal = player == 1 ? 1:-1;
            }else if( (antidiagonal>0&&player==1) || 
                      (antidiagonal<0&&player==2) ){
                antidiagonal += player == 1 ? 1:-1;
                if(antidiagonal==n || antidiagonal==-n){
                    return player;
                }
            }else{
                antidiagonal = 0;
            }
        }
        
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */

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
