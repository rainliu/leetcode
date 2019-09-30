class Solution {
    static constexpr const int offset_x[4] = {-1,1,0,0};
    static constexpr const int offset_y[4] = {0,0,-1,1};
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(); if (m==0) {return false;}    
        int n = maze[0].size(); if (n==0) {return false;}
        vector<vector<bool>> visited(m, vector(n, false));
        return dfs(maze, start, destination, visited);
    }
    
    bool dfs(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination, vector<vector<bool>>& visited){
        visited[start[0]][start[1]] = true;
        for(int d=0; d<4; ++d){
            auto stop = nextStop(maze, start, d);
            if (stop[0]==destination[0] && stop[1]==destination[1]){
                return true;
            }
            if (!visited[stop[0]][stop[1]]) {
                if (dfs(maze, stop, destination, visited)) {
                    return true;
                }
            }
        }        
        return false;
    }
    
    vector<int> nextStop(vector<vector<int>>& maze, vector<int>& start, int d) {
        vector<int> stop{start[0], start[1]};
        while(stop[0]+offset_y[d]>=0&&stop[0]+offset_y[d]<maze.size() &&
              stop[1]+offset_x[d]>=0&&stop[1]+offset_x[d]<maze[0].size() &&
              maze[stop[0]+offset_y[d]][stop[1]+offset_x[d]]!=1){
            stop[0]+=offset_y[d];
            stop[1]+=offset_x[d];
        }   
        return stop;
    }
};
