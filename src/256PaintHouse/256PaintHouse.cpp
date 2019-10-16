class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        vector<int> D(3, 0);
        vector<int> d(3, 0);
        for(const auto&cost : costs){
            for(int i=0; i<3; ++i){
                d[i]=D[i];
            }
            D[0]=cost[0]+min(d[1], d[2]);
            D[1]=cost[1]+min(d[0], d[2]);
            D[2]=cost[2]+min(d[0], d[1]);
        }
        return min(min(D[0], D[1]), D[2]);
    }
};
