class Solution {
    static constexpr int offset_x[4] = {-1,1,0,0};
    static constexpr int offset_y[4] = {0,0,-1,1};
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(); if(m==0) return false;
        int n=board[0].size(); if(n==0) return false;
        if(word.size()==0) return false;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int j=0; j<m; ++j){
            for(int i=0; i<n; ++i){
                if(board[j][i]==word[0]){
                    if(dfs(board, word, visited, i, j, m, n, 1)) return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string& word, vector<vector<bool>>& visited, int i, int j, int m, int n, int k){
        if(k == word.size()) return true;
            
        visited[j][i] = true;
        for(int d = 0; d < 4; ++d){
            int x = i+offset_x[d];
            int y = j+offset_y[d];
            if(x>=0&&x<n&&y>=0&&y<m&&!visited[y][x]&&board[y][x]==word[k]){
                if(dfs(board, word, visited, x, y, m, n, k+1)) return true;
            }
        }        
        
        visited[j][i] = false;
        return false;
    }
};
