class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> a;
        backtracking(a, 0, nums, results);
        return results;
    }
    
    void backtracking(vector<int>& a, int k, vector<int>& nums, vector<vector<int>>& results){
        if(is_solution(a, k, nums)){
            process_solution(a, k, nums, results);
        }else{
            auto cands = contruct_candidates(a, k, nums);
            ++k;
            for(const auto& cand: cands){
                a.push_back(cand);
                backtracking(a, k, nums, results);
                a.pop_back();
            }
        }
    }
    
    bool is_solution(vector<int>& a, int k, vector<int>& nums){
        return k==nums.size();
    }
    
    void process_solution(vector<int>& a, int k, vector<int>& nums, vector<vector<int>>& results){
        results.push_back(a);
    }
    
    vector<int> contruct_candidates(vector<int>& a, int k, vector<int>& nums) {
        unordered_set<int> s;
        for(const auto& num: a){
            s.insert(num);
        }
        vector<int> cands;
        for(const auto& num: nums){
            if(s.find(num) == s.end()){
                cands.push_back(num);
            }
        }
        return cands;
    }
};
