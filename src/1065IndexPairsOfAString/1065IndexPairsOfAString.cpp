class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        vector<vector<int>> results;
        for(const auto& word : words){
            auto result = matches(text, word);
            for(const auto index: result){
                results.push_back({index, index+word.size()-1});
            }
        }
        sort(results.begin(), results.end());
        return results;
    }
    vector<int> matches(const string& text, const string& word){
        int N = text.size();
        int M = word.size();
        vector<int> right(26, -1);
        for(int j=0; j<M; ++j){
            right[word[j]-'a']=j;
        }
        
        vector<int> result;
        int skip;
        for(int i = 0; i <= N - M; i += skip){
            skip = 0;
            for(int j=M-1; j>=0; --j){
                if(word[j]!=text[i+j]){
                    skip = max(1, j-right[text[i+j]-'a']);
                    break;
                }        
            }
            if(skip == 0){
                result.push_back(i);
                skip = 1;
            }
        }
        return result;
    }
};
