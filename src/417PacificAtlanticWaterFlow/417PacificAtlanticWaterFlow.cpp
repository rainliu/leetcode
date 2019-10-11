class Solution {
    static constexpr int offset_x[4]={-1,1,0,0};
    static constexpr int offset_y[4]={0,0,-1,1};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> result;
        int m = matrix.size(); if(m==0) return result;
        int n = matrix[0].size(); if(n==0) return result;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        
        bfs(matrix, visited, 0x1, m, n);
        bfs(matrix, visited, 0x2, m, n);
        
        for(int j=0; j<m; ++j){
            for(int i=0; i<n; ++i){
                if(visited[j][i]==0x3){
                    result.push_back(vector<int>{j, i});
                }
            }
        }
        return result;
    }
    
    void bfs(vector<vector<int>>& matrix, vector<vector<int>>& visited, int mask, int m, int n) {
        queue<pair<int,int>> q;
        for(int i=0; i<n; ++i){
            q.push({i, mask == 0x1 ? 0: m-1});
            visited[mask == 0x1 ? 0: m-1][i] |= mask;
        }
        int offset = mask == 0x1 ? 0 : 1; 
        for(int j=1-offset; j<m-offset; ++j){
            q.push({mask == 0x1 ? 0: n-1, j});
            visited[j][mask == 0x1 ? 0: n-1] |= mask;
        }
        while(!q.empty()){
            auto [i, j] = q.front(); q.pop();
            for(int d=0; d<4; ++d){
                int x = i+offset_x[d];
                int y = j+offset_y[d];
                if(x>=0&&x<n&&y>=0&&y<m&&
                   (visited[y][x]&mask)==0&&
                   matrix[y][x]>=matrix[j][i]){
                    q.push({x,y});
                    visited[y][x] |= mask;
                }
            }
        }
    }
};
