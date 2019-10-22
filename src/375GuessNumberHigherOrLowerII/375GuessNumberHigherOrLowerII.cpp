class Solution {
public:
    int getMoneyAmount(int n) {
        if(n<=1) return 0;        
        vector<vector<int>> D(n+1, vector<int>(n+1,0));        
        for(int j=n-1; j>=1; --j){
            for(int i=1; i<=j; ++i){
                D[i][i+n-j] = numeric_limits<int>::max();
                for(int k=i; k<=i+n-j; ++k){
                    D[i][i+n-j] = min(D[i][i+n-j], k+max(D[i][k-1], k<i+n-j ? D[k+1][i+n-j] : 0));
                }
            }
        }

        return D[1][n];
    }
};
