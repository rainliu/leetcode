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