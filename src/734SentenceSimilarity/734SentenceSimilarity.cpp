class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if (words1.size() != words2.size()) return false;
        unordered_map<string, unordered_set<string>> m;
        for(const auto& pair: pairs) {
            m[pair[0]].insert(pair[1]);
            m[pair[1]].insert(pair[0]);
        }
        for(int i=0; i<words1.size(); ++i){
            if ( words1[i]==words2[i] || 
                (m.find(words1[i])!=m.end() &&
                 m[words1[i]].find(words2[i])!=m[words1[i]].end())
               ){
                continue;
            }else{            
                return false;
            }
        }
        return true;
    }
};
