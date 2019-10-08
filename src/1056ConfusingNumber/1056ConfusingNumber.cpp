class Solution {
public:
    bool confusingNumber(int N) {
        int M = reverse(N);
        if (M==-1) {
            return false;
        }
        return N!=M;
    }
    int reverse(int N) {
        if(N<0) return -1;
        int M=0;
        while(N>0) {
            int d = N%10;
            switch(d) {
                case 2:
                case 3:
                case 4:
                case 5:
                case 7: return -1;
                case 6: M = M*10+9; break;
                case 9: M = M*10+6; break;
                default: M= M*10+d; 
            }
            N/=10;
        }
        return M;
    }
};
