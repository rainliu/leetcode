class Solution {   
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size(); if (m==0) return board;
        int n = board[0].size(); if(n==0) return board;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<int> q;
        int count = checkMines(board, click, m, n);
        if(count == 9) return board;
        if(count == 0) {
            visited[click[0]][click[1]] = true;
            q.push(click[0]*n+click[1]);
        }
        while (!q.empty()) {
            int p = q.front(); q.pop();
            for(int j = -1; j <= 1; ++j) {
                for(int i = -1; i <= 1; ++i) {
                    click[0] = p/n+j;
                    click[1] = p%n+i;
                    if (click[1]>=0 && click[1] < n && 
                        click[0]>=0 && click[0] < m &&
                        !visited[click[0]][click[1]]) {
                        int count = checkMines(board, click, m, n);
                        if(count == 9) return board;
                        if(count == 0) {
                            visited[click[0]][click[1]] = true;
                            q.push(click[0]*n+click[1]);
                        }
                    }
                }
            }
        }
        
        return board;
    }
    
    int checkMines(vector<vector<char>>& board, vector<int>& click, int m, int n) {
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return 9;
        }
        int count = 0;
        for(int j = -1; j <= 1; ++j) {
            for(int i = -1; i <= 1; ++i) {
                int x = click[1]+i;
                int y = click[0]+j;
                if (x>=0 && x < n && y>=0 && y < m && board[y][x] == 'M'){
                    ++count;
                }
            }
        }
        if (count == 0) {
            board[click[0]][click[1]] = 'B';
        }else{
            board[click[0]][click[1]] = '0' + count;
        }
        return count;
    }
};
