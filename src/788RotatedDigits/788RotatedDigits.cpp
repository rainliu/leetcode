class Solution {
public:
    int rotatedDigits(int N) {
        int count = 0;
        for (int n=1; n<=N; ++n){
            if(isValid(n)) ++count;
        }
        return count;
    }
    
    bool isValid(int N) {
        bool valid = false;
        while (N>0) {
            int n = N%10;
            switch(n){
                case 2:
                case 5:
                case 6:
                case 9: valid=true; break;
                case 3:
                case 4:
                case 7: return false;
            }
            N/=10;
        }
        
        return valid;
    }
};
