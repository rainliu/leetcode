class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        // D[j, diff] = 1+max_i(D[i, diff]*((D[j]-D[i])==diff))
        vector<unordered_map<int,int>> D(A.size());
        int global = 0;
        for(int j=1; j<A.size(); ++j){
            for(int i=0; i<j; ++i){
                int diff = A[j]-A[i];
                D[j][diff] = max(D[j][diff], 1 + D[i][diff]);
                global = max(global, D[j][diff]);
            }
        }
        return global+1;
    }
};
