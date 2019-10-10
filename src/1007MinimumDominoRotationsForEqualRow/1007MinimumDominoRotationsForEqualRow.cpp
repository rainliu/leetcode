class Solution {
public: //check A[0] or B[0] is enough since if both of them can't, then no way
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int count_A = check(A, B, A[0]);
        int count_B = check(A, B, B[0]);
        return count_A==A.size()&&count_B==B.size() ? -1 : min(count_A, count_B);
    }
    int check(vector<int>& A, vector<int>& B, int x){
        int count_A = 0;
        int count_B = 0;
        for(int i = 0; i < A.size(); ++i){
            if(A[i]!=x&&B[i]!=x) {
                count_A = count_B = A.size();
                break;
            }
            if(A[i]!=x) ++count_A;
            if(B[i]!=x) ++count_B;            
        }
        
        return min(count_A, count_B);
    }
};
