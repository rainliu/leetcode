class Solution {
    static constexpr int offset_x[4]={-1,1,0,0};
    static constexpr int offset_y[4]={0,0,-1,1};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> result;
        int m = matrix.size(); if(m==0) return result;
        int n = matrix[0].size(); if(n==0) return result;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<int,int>> q;
        for(int i=0; i<n; ++i){
            q.push({i,0});
            visited[0][i] |= 0x1;
        }
        for(int j=1; j<m; ++j){
            q.push({0,j});
            visited[j][0] |= 0x1;
        }
        while(!q.empty()){
            auto [i, j] = q.front(); q.pop();
            for(int d=0; d<4; ++d){
                int x = i+offset_x[d];
                int y = j+offset_y[d];
                if(x>=0&&x<n&&y>=0&&y<m&&
                   (visited[y][x]&0x1)==0&&
                   matrix[y][x]>=matrix[j][i]){
                    q.push({x,y});
                    visited[y][x] |= 0x1;
                }
            }
        }
        
        queue<pair<int,int>> p;
        for(int i=0; i<n; ++i){
            p.push({i,m-1});
            visited[m-1][i] |= 0x2;
        }
        for(int j=0; j<m-1; ++j){
            p.push({n-1,j});
            visited[j][n-1] |= 0x2;
        }
        while(!p.empty()){
            auto [i, j] = p.front(); p.pop();
            for(int d=0; d<4; ++d){
                int x = i+offset_x[d];
                int y = j+offset_y[d];
                if(x>=0&&x<n&&y>=0&&y<m&&
                   (visited[y][x]&0x2)==0&&
                   matrix[y][x]>=matrix[j][i]){
                    p.push({x,y});
                    visited[y][x] |= 0x2;
                }
            }
        }
        for(int j=0; j<m; ++j){
            for(int i=0; i<n; ++i){
                if(visited[j][i]==0x3){
                    result.push_back(vector<int>{j, i});
                }
            }
        }
        return result;
    }
};
