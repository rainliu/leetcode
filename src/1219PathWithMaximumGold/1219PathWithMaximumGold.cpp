class Solution {
    static constexpr int offset_x[4]={-1,1,0,0};
    static constexpr int offset_y[4]={0,0,-1,1};
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size(); if(m==0) return 0;
        int n=grid[0].size(); if(n==0) return 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int global = 0;
        for(int j=0; j<m; ++j){
            for(int i=0; i<n; ++i){
                if(grid[j][i]>0){
                    dfs(grid, visited, i, j, m, n, 0, global);    
                }
            }
        }
        return global;
    }
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, int m, int n, int local, int& global){
        visited[j][i]=true;
        local += grid[j][i];
        global = max(global, local);
        for(int d=0; d<4; ++d){
            int x = i+offset_x[d];
            int y = j+offset_y[d];
            if(x>=0&&x<n&&y>=0&&y<m&&!visited[y][x]&&grid[y][x]>0){
                dfs(grid, visited, x, y, m, n, local, global);
            }
        }
        
        visited[j][i]=false;
    }
};
