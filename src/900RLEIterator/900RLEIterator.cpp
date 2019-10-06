class RLEIterator {
    map<long long, int> m;
    long long sum;
public:
    RLEIterator(vector<int>& A) {
        sum = 0;
        for(int i=0; i<A.size(); ++i){
            if(i%2==0){
                sum += A[i];
            }else if(A[i-1]>0){
                m[sum] = A[i];       
            }
        }
        sum = 0;
    }
    
    int next(int n) {
        sum += n;
        auto it = m.lower_bound(sum);
        if (it!=m.end()){
            return it->second;           
        }else{
            return -1;
        }
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */
