class Solution {
public:
    int numWays(int n, int k) {
        // S[i] = D[i-1]*1,       (p[i]==p[i-1])
        // D[i] = G[i-1]*(k-1)    (p[i]!=p[i-1])
        // G[i] = S[i]+D[i]
        if(n==0) return 0;
        int S = 0;
        int D = k;
        int G = k;
        for(int i=1; i<n; ++i){
            S = D;
            D = G*(k-1);
            G = S+D;
        }            
        return G;
    }
};
