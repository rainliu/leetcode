class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        int pos = 0;
        while(pos<n&&A[pos]<0) {
            ++pos;
        }
        int i = pos;
        int j = pos-1;
        int k = 0;
        vector<int> result(n, 0);
        while(k<n){
            if(i>=n){
                result[k] = A[j]*A[j]; --j;
            }else if(j<0){
                result[k] = A[i]*A[i]; ++i;
            }else{
                if(A[i]*A[i]<A[j]*A[j]){
                    result[k] = A[i]*A[i]; ++i;
                }else{
                    result[k] = A[j]*A[j]; --j;
                }
            }
            ++k;
        }
        
        return result;
    }
};
