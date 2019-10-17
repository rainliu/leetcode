class Solution {
public:
    double new21Game(int N, int K, int W) {
        // D[x] = (1/W)*[D[x+1]+D[x+2]+...+D[x+W]]
        vector<double> D(N+W+1, 0);
        for(int k=K; k<=N; ++k){
            D[k] = 1.0;
        }
        double S = min(N-K+1, W);
        for(int k=K-1; k>=0; --k){
            D[k]=S/W;
            S += D[k]-D[k+W];
        }
        return D[0];
    }
};


class Solution {
public:
    double new21Game(int N, int K, int W) {
        // D[x] = (1/W)*[D[x+1]+D[x+2]+...+D[x+W]]
        vector<double> D(N+1, 0);
        for(int k=K; k<=N; ++k){
            D[k] = 1.0;
        }
        for(int k=K-1; k>=0; --k){
            double sum = 0;
            for(int i=1; i<=W; ++i){
                if(k+i<=N){
                    sum += D[k+i];
                }
            }
            D[k]=sum/W;
        }
        return D[0];
    }
};
