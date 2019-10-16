class Solution {
public:
    bool divisorGame(int N) {
        vector<bool> D(N+1, false);
        D[0]=false;
        D[1]=false;
        D[2]=true;
        for(int i=3; i<=N; ++i){
            for(int x=1; x<i; ++x){
                if(i%x==0){
                    if(!D[i-x]){
                        D[i]=true;
                        break;
                    }
                }
            }    
        }
        return D[N];
    }
};
