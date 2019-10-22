class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const auto& a, const auto& b){
            return a.size() < b.size();    
        });  
        
        vector<int> D(words.size(), 0);
        D[0] = 1;
        int global = 0;
        for(int j=1; j<words.size(); ++j){
            int local = 0;
            for(int i=0; i<j; ++i){
                local = max(local, is_predecessor(words[i], words[j]) ? D[i] : 0);
            }
            D[j]=1+local;
            global = max(global, D[j]);
        }
        return global;
    }
    
    bool is_predecessor(const string&a, const string& b){
        if(a.size()+1!=b.size()) return false;
        
        int i = 0;
        int j = 0;
        while(i<a.size()&&j<b.size()){
            if(a[i]==b[j]){
                ++i;
            }
            ++j;
        }
        return i==a.size();
    }
};
