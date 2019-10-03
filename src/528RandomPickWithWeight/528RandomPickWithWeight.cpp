class Solution {
    vector<int> count;
public:
    Solution(vector<int>& w) {
        int c = 0;
        for (auto x: w) {
            c+=x;
            count.push_back(c);
        }
    }
    
    int pickIndex() {
        if (count.empty()) return -1;
        int total = count[count.size()-1];
        int c = rand()%total;
        return binarySearch(c);
    }
    
    int binarySearch(int c){
        int lo = 0;
        int hi = count.size() - 1;
        while (lo<=hi) {
            int mi = lo + (hi-lo)/2;
            if (count[mi] == c) {
                return mi+1;
            }else if (count[mi] < c) {
                lo = mi + 1;
            }else{
                hi = mi - 1;
            }
        }
        return lo >count.size()-1 ? count.size()-1 : lo;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
