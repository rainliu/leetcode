class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int i=0;
        vector<int> js(words.size(), 0);
        while(i<S.size()){
            for(int j=0; j<words.size(); ++j){
                if(js[j]<words[j].size() && S[i]==words[j][js[j]]){
                    ++js[j];
                }
            }
            ++i;
        }
        int count = 0;
        for(int j=0; j<words.size(); ++j){
            count += js[j]==words[j].size();
        }
        return count;
    }
};

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        unordered_map<string, bool> m;
        int count = 0;
        for(const auto& word : words){
            bool r;
            if(m.find(word) == m.end()){
                r = is_subseq(S, word);
                m[word]=r;
            }else{
                r = m[word];
            }
            count += r;
            
        }
        return count;
    }
    
    bool is_subseq(const string& S, const string& word){
        int n=S.size();
        int m=word.size();
        int i=0;
        int j=0;
        while(i<n&&j<m){
            if(S[i]==word[j]){
                ++j;
            }
            ++i;
        }
        return j==m;
    }
};
