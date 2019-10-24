class Solution {
public:
    vector<vector<string>> partition(string s) {
        return partition(s, 0, int(s.size())-1);
    }
    
    vector<vector<string>> partition(string& s, int lo, int hi) {
        vector<vector<string>> results;
        for(int i=lo; i<=hi; ++i){
            if(is_palindrome(s, lo, i)){
                auto ss = s.substr(lo,i-lo+1);
                auto result = partition(s, i+1, hi);
                if(!result.empty()){
                    for(auto& res : result){
                        res.insert(res.begin(), ss);
                    }
                }else{
                    result.push_back(vector<string>{ss});
                }
                
                
                copy(result.begin(), result.end(), back_inserter(results));
            }    
        }    
        return results;
    }
    
    bool is_palindrome(string& s, int lo, int hi){
        while(lo<hi){
            if(s[lo++]!=s[hi--]){
                return false;
            }
        }
        return true;
    }
};
