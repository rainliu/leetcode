class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int repeat = 0;
        string C = A;
        for(repeat=1; repeat<= 2 + B.size()/A.size() ; ++repeat) {
            if(C.find(B)!=string::npos){
                return repeat;
            }else{
                C+=A;
            }
        }
        return -1;
    }
};
