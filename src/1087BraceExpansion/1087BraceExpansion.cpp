class Solution {
public:
    vector<string> expand(string S) {
        vector<vector<char>> words;
        int i = 0;
        while(i<S.size()){
            if(S[i]=='{'){
                vector<char> chars;
                while(++i<S.size() && S[i] != '}'){
                    if(S[i]!=','){
                        chars.push_back(S[i]);
                    }
                }
                words.push_back(chars);    
            }else{
                words.push_back(vector<char>{S[i]});
            }
            ++i;
        }
        vector<string> result;
        vector<char> a;
        backtracking(a, 0, words, result);
        sort(result.begin(), result.end());
        return result;
    }

    void backtracking(vector<char>& a, int k, vector<vector<char>>& words, vector<string>& result){
        if(is_solution(k, words.size())){
            process_solution(a, result);
        }else{
            auto cands = construct_candidates(k, words);
            ++k;
            for(const auto& cand : cands){
                a.push_back(cand);
                backtracking(a, k, words, result);
                a.pop_back();
            }
        }
    }

    bool is_solution(int k, int n) {
        return k == n;
    }

    void process_solution(vector<char>& a, vector<string>& result){
        ostringstream oss;
        for(const auto& ch : a){
            oss<<ch;
        }
        result.push_back(oss.str());
    }

    vector<char> construct_candidates(int k, vector<vector<char>>& words) {
        return words[k];
    }
};
