class Solution {
    static constexpr int offset_x[8] = {-1,0,1,-1,1,-1,0,1};
    static constexpr int offset_y[8] = {-1,-1,-1,0,0,1,1,1};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(); if(m==0) return -1;
        int n = grid[0].size(); if(n==0) return -1;
        if(grid[0][0]==1||grid[m-1][n-1]==1) return -1;
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        queue<tuple<int,int,int>> q;
        q.push({0,0,1});
        visited[0][0]=true;
        while(!q.empty()){
            auto [i,j,l] = q.front(); q.pop();
            if(i==n-1&&j==m-1) return l;
            for(int d=0; d<8; ++d){
                int x = i+offset_x[d];
                int y = j+offset_y[d];
                if(x>=0&&x<n&&y>=0&&y<m&&!visited[y][x]&&grid[y][x]==0){
                    q.push({x,y,l+1}); 
                    visited[y][x]=true;
                }
            }
        }
        return -1;
    }
};
