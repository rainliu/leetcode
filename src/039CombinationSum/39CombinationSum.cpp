class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> a;
        int sum = 0;
        backtracking(a, 0, candidates, target, sum, results);
        return results;
    }
    
    void backtracking(vector<int>& a, int k, vector<int>& candidates, int target, int& sum, vector<vector<int>>& results){
        if(sum>target) return;
        
        if(is_solution(a, k, candidates, target, sum)){
            process_solution(a, k, candidates, target, results);
        }else if(k<candidates.size()){
            auto cands = construct_candidates(a, k, candidates, target);
            for(const auto& cand : cands) {
                a.push_back(cand);
                sum+=cand;
                backtracking(a, k, candidates, target, sum, results);
                sum-=cand;
                a.pop_back();
            }
            backtracking(a, ++k, candidates, target, sum, results);
        }
    }
    
    bool is_solution(vector<int>& a, int k, vector<int>& candidates, int target, int& sum){
        return sum==target;
    }
    
    void process_solution(vector<int>& a, int k, vector<int>& candidates, int target, vector<vector<int>>& results){
        results.push_back(a);
    }
    
    vector<int> construct_candidates(vector<int>& a, int k, vector<int>& candidates, int target){
        return vector<int>{candidates[k]};
    }
};
