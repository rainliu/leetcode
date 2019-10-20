class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> result;
        for(const auto& query : queries){
            result.push_back(match(query, pattern));
        }
        return result;
    }
    bool match(const string& query, const string& pattern){
        int i=0;
        int j=0;
        while(i<query.size()&&j<pattern.size()){
            if(query[i]==pattern[j]){
                ++j;
            }else if(query[i]>='A'&&query[i]<='Z'){
                return false;
            }
            ++i;
        }
        if(j!=pattern.size()) return false;
        while(i<query.size()){
            if(query[i]>='A'&&query[i]<='Z'){
                return false;
            }    
            ++i;
        }
        return true;
    }
};
