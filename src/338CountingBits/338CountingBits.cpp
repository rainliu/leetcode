class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> D(num+1, 0);
        D[0] = 0;
        int highest_bit_pos = 1;
        for(int i=1; i<=num; ++i){
            if(i<(1<<highest_bit_pos)){
                D[i] = 1 + D[i-(1<<(highest_bit_pos-1))];
            }else{
                ++highest_bit_pos;
                D[i]=1;
            }  
        }
        return D;
    }
};
