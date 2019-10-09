class Solution {
    static constexpr int offset_x[8] = {-2,-1,1,2,2,1,-1,-2};
    static constexpr int offset_y[8] = {1,2,2,1,-1,-2,-2,-1};
public:
    int minKnightMoves(int x, int y) {
        unordered_set<int> visited;
        queue<tuple<int,int,int>> q;
        q.push({0, 0, 0});
        visited.insert(hash(0,0));
        while(!q.empty()){
            // C++17 structured binding:
            auto [i, j, l] = q.front(); q.pop();
            if(i==x && j==y) return l;
            for(int d=0; d<8; ++d){
                int u = i+offset_x[d];
                int v = j+offset_y[d];
                if (visited.find(hash(u,v)) == visited.end()) {
                    q.push({u,v,l+1});
                    visited.insert(hash(u,v));
                }
            }
        }
        return 0;
    }
    
    int hash(int x, int y) {
        return (y+300)*601+(x+300);
    }
};
