class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int lo = 0;
        int hi = int(A.size()) - 1;
        while (lo <= hi) {
            int mi = lo + (hi-lo)/2;
            if (A[mi] > A[mi+1] && A[mi] > A[mi-1]){
                return mi;
            }else if (A[mi-1] < A[mi] && A[mi] < A[mi+1]) {
                lo = mi + 1;
            }else{
                hi = mi - 1;
            }
        }
        return -1;
    }
};
