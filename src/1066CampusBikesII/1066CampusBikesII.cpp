class Solution {
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<vector<int>> distances(workers.size(), vector<int>(bikes.size(), 0));
        for(int i=0; i<workers.size(); ++i){
            for(int j=0; j<bikes.size(); ++j){
                distances[i][j] = abs(workers[i][0]-bikes[j][0]) + abs(workers[i][1]-bikes[j][1]);
            }
        }   
        int global = numeric_limits<int>::max();
        vector<int> a;
        backtracking(a, 0, workers.size(), distances, global);
        return global;
    }
    
    void backtracking(vector<int>& a, int k, int n, vector<vector<int>>& distances, int& global) {
        if(is_solution(a, k, n)){
            process_solution(a, k, n, distances, global);
        }else{
            auto cands = construct_candidates(a, k, n, distances[0].size());
            ++k;
            for(const auto& cand: cands) {
                a.push_back(cand);
                backtracking(a, k, n, distances, global);
                a.pop_back();
            }
        }
    }
    
    bool is_solution(vector<int>& a, int k, int n) {
        return k==n;
    }
    
    void process_solution(vector<int>& a, int k, int n, vector<vector<int>>& distances, int& global) {
        int local = 0;
        for(int i=0; i<a.size(); ++i){
            local+=distances[i][a[i]];
        }
        global = min(global, local);
    }
    
    vector<int> construct_candidates(vector<int>& a, int k, int n, int m){
        vector<bool> used(m, false);
        for(const auto& bike : a){
            used[bike] = true;
        }
        vector<int> cands;
        for(int i=0; i<m; ++i){
            if(!used[i]) {
                cands.push_back(i);
            }
        }
        return cands;
    }
};
