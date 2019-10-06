class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        map<int,int> m;
        for(int l=0; l<indexes.size(); ++l){
            m[-indexes[l]]=l;
        }
        for(auto& p : m){
            int l = p.second;           
            if(S.substr(indexes[l], sources[l].size())==sources[l]){
                S.replace(indexes[l], sources[l].size(), targets[l]);
            }
        }
        return S;
    }
};
