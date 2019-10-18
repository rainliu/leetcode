class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(); if(n==0) return 0;
        vector<int> D{0,-prices[0],0};
        for(int j=1; j<n; ++j){
            int t0 = D[0];
            int t1 = D[1];
            int t2 = D[2];
            D[0]=max(t0, t2);
            D[1]=max(t1, t0-prices[j]);
            D[2]=t1+prices[j];            
        }
        return max(max(D[0], D[1]), D[2]);
    }
};
