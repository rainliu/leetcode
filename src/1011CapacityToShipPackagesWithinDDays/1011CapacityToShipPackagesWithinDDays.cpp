class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int hi = std::accumulate(weights.begin(), weights.end(), 0);
        int lo = 1;
        while(lo<=hi){
            int mi = lo + (hi-lo)/2;
            if(possible(weights, D, mi)){
                hi = mi - 1;
            }else{
                lo = mi + 1;
            }
        }
        return hi+1;
    }
    
    bool possible(vector<int>& weights, int D, int capacity) {
        int d = 1;
        int load = 0;
        int i = 0;
        while(i < weights.size()){
            if(load+weights[i] > capacity) {
                load = 0;
                ++d;
                if(d>D){
                    return false;
                }
            }else{
                load+=weights[i++];
            }
        }
        return d <= D;
    }
        
};
