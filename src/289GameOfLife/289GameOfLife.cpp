class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(); if(m==0) return;
        int n = board[0].size(); if(n==0) return;
        for(int j=0; j<m; ++j){
            for(int i=0; i<n; ++i){
                int c = 0;
                for(int v=-1; v<=1; ++v){
                    for(int u=-1; u<=1; ++u){
                        if(u==0&&v==0) continue;
                        int x = i+u;
                        int y = j+v;
                        if(x>=0&&x<n&&y>=0&&y<m){
                            c += board[y][x]&0x1;
                        }
                    }
                }
                if(board[j][i]&0x1){
                    if(c==2||c==3){
                        board[j][i] |= 0x2;
                    }
                }else{
                    if(c==3){
                        board[j][i] |= 0x2;
                    }
                }
            }
        }
        for(int j=0; j<m; ++j){
            for(int i=0; i<n; ++i){
                board[j][i]>>=1;
            }
        }
    }
};

#include <vector>
using namespace std;

class Solution {
public:
  void gameOfLife(vector<vector<int>> &board) {
    int m = board.size();
    if (m == 0)
      return;
    int n = board[0].size();
    if (n == 0)
      return;

    for (int j = 0; j < m; j++) {
      for (int i = 0; i < n; i++) {
        int c = 0;
        for (int y = -1; y <= 1; y++) {
          for (int x = -1; x <= 1; x++) {
            if (x == 0 && y == 0)
              continue;
            if (j + y >= 0 && j + y < m && i + x >= 0 && i + x < n) {
              c += board[j + y][i + x] & 0x1;
            }
          }
        }
        if (board[j][i] & 0x1) {
          if (c == 2 || c == 3) {
            board[j][i] |= 0x2;
          }
        } else {
          if (c == 3) {
            board[j][i] |= 0x2;
          }
        }
      }
    }

    for (int j = 0; j < m; j++) {
      for (int i = 0; i < n; i++) {
        board[j][i] >>= 1;
      }
    }
  }
};

int main() { return 0; }
