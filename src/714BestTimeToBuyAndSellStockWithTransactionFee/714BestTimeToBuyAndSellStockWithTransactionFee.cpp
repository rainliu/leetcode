//   S0==Rest=>S0
//   S0==Buy==>S1
//   S1==Rest=>S1
//   S1==Sell=>S0

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size()==0) return 0;
        int S0 = 0;
        int S1 = -prices[0]-fee;
        for(int i=1; i<prices.size(); ++i){
            int T0 = max(S0, S1+prices[i]);
            int T1 = max(S1, S0-prices[i]-fee);
            S0 = T0;
            S1 = T1;
        }
        return max(S0, S1);
    }
};
