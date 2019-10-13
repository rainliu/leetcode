class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> results;
        vector<bool> a;
        backtracking(a, 0, n, k, results);
        return results;
    }
    
    void backtracking(vector<bool>&a, int i, int n, int k, vector<vector<int>>& results){
        if(is_solution(a, i, n, k)){
            process_solution(a, i, n, k, results);
        }else if(i<n){
            auto cands = construct_candidates(a, i, n, k);
            ++i;
            for(const auto& cand : cands) {
                a.push_back(cand);
                backtracking(a, i, n, k, results);
                a.pop_back();
            }
        }
    }
    
    bool is_solution(vector<bool>&a, int i, int n, int k) {
        return i==n && k == std::count(a.begin(), a.end(), true);
    }
    
    void process_solution(vector<bool>&a, int i, int n, int k, vector<vector<int>>& results) {
        vector<int> result;
        for(int j=0; j<n; ++j){
            if(a[j]) result.push_back(j+1);
        }
        results.push_back(result);
    }
    
    vector<bool> construct_candidates(vector<bool>&a, int i, int n, int k) {
        return vector<bool>{true, false};
    }
};
