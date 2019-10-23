class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for(int i=0; i<s.size(); ++i){
            for(int j=i; j<s.size(); ++j){
                count+=is_palidromic(s, i, j);
            }
        }    
        return count;
    }
    
    bool is_palidromic(string&s, int lo, int hi){
        while(lo<hi){
            if(s[lo++]!=s[hi--]) return false;    
        }
        return true;
    }
};
