class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> results;
        vector<int> a;
        backtracking(a, 0, k, 9, n, results);
        return results;
    }
    
    void backtracking(vector<int>& a, int i, int k, int n, int target, vector<vector<int>>& results){
        if(is_solution(a, i, k, n, target)){
            process_solution(a, results);
        }else if(i<n){
            auto cands = construct_candidates();
            ++i;
            for(const auto& cand : cands){
                if(cand){
                    a.push_back(i);
                }
                backtracking(a, i, k, n, target - (cand ? i : 0), results);
                if(cand){
                    a.pop_back();
                }
            }
        }
    }
    
    bool is_solution(vector<int>& a, int i, int k, int n, int target) {
        return i==n && a.size() == k && 0==target;
    }
    
    void process_solution(vector<int>& a, vector<vector<int>>& results) {
        results.push_back(a);
    }
    
    vector<bool> construct_candidates(){
        return vector<bool>{true, false};
    }
};

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
  vector<int> contructCands(vector<int> &result) {
    vector<int> cands;
    if (result.size() == 0) {
      for (int c = 1; c <= 9; c++) {
        cands.push_back(c);
      }
    } else {
      for (int c = result[result.size() - 1] + 1; c <= 9; c++) {
        cands.push_back(c);
      }
    }
    return cands;
  }
  void backtracking(vector<vector<int>> &results, vector<int> &result, int i,
                    int k, int n) {
    if (i == k) {
      int sum = 0;
      for (int j = 0; j < k; j++) {
        sum += result[j];
      }
      if (sum == n) {
        results.push_back(result);
      }
    } else {
      i++;
      auto cands = contructCands(result);
      for (int j = 0; j < cands.size(); j++) {
        result.push_back(cands[j]);
        backtracking(results, result, i, k, n);
        result.pop_back();
      }
    }
  }

public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> results;
    vector<int> result;
    backtracking(results, result, 0, k, n);
    return results;
  }
};

int main() { return 0; }
