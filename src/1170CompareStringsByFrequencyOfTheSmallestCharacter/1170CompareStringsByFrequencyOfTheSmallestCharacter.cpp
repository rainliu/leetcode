class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> queries_counts(queries.size(), 0);    
        vector<int> words_counts(words.size(), 0);
        for(int i=0; i<queries.size(); ++i){
            queries_counts[i]=frequency(queries[i]);
        }
        for(int i=0; i<words.size(); ++i){
            words_counts[i]=frequency(words[i]);
        }
        sort(words_counts.begin(), words_counts.end());
        
        vector<int> result(queries.size(), 0);
        for(int i=0; i<queries.size();++i){
            auto it = std::upper_bound(words_counts.begin(), words_counts.end(), queries_counts[i]);
            result[i] = it == words_counts.end() ? 0 : words_counts.size()-(it-words_counts.begin());
        }
        return result;
    }
    
    int frequency(string& s){
        sort(s.begin(), s.end());
        auto p = s.begin();
        int c = 1;
        auto q = p+1;
        while(q!=s.end() && *q==*p){
            ++c;
            ++q;
        }
        return c;
    }
    
};
