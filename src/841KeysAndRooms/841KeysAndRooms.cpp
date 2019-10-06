class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        int cc = 0;
        for(int i=0; i<n; ++i){
            if(!visited[i]) {
                if(++cc>1) return false;
                dfs(rooms, visited, i);
            }
        }
        return true;
    }
    
    void dfs(vector<vector<int>>& rooms, vector<bool>& visited, int i) {
        visited[i] = true;
        for(int j : rooms[i]) {
            if(!visited[j]) {
                dfs(rooms, visited, j);
            }
        }
    }
};
