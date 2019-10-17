class Solution {
public:
    int shortestWay(string source, string target) {
        vector<bool> m(26, false);
        for(const auto& ch : source) {
            m[ch-'a'] = true;
        }
        int count = 0;
        int i = 0;
        int j = 0;
        while(j<target.size()){
            if(!m[target[j]-'a']) return -1;
            if(source[i]==target[j]){
                ++j;
            }
            ++i;
            if(i==source.size()){
                ++count;
                i=0;
            }
        }
        
        return count + (i>0);
    }
};
