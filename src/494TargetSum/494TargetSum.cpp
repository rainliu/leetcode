class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<vector<int>> D(nums.size(), vector<int>(1000*2+1, 0));
        D[0][nums[0]+1000]+=1;
        D[0][-nums[0]+1000]+=1;
        for(int i=1; i<nums.size(); ++i){
            for(int sum=-1000; sum<=1000; ++sum){
                if(D[i-1][sum+1000]>0){
                    D[i][sum+nums[i]+1000] += D[i-1][sum+1000];
                    D[i][sum-nums[i]+1000] += D[i-1][sum+1000];
                }
            }
        }
        return S > 1000 ? 0 : D[nums.size()-1][S+1000];
    }
};

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int global = 0;
        backtracking(0, nums, S, global);
        return global;
    }
    
    void backtracking(int k, vector<int>& nums, int S, int& global){
        if(k==nums.size()&&0==S){
            ++global;       
        }else if(k<nums.size()){
            auto cands = contruct_candidates(k, nums);
            ++k;
            for(const auto& cand : cands){
                S -= cand;
                backtracking(k, nums, S, global);
                S += cand;
            }
        }
    }
    
    vector<int> contruct_candidates(int k, vector<int>& nums){
        return vector<int>{nums[k], -nums[k]};
    }
};

#include <vector>
using namespace std;

class Solution {
private:
  void backtracking(vector<int> &nums, int S, int k, int n, int sum,
                    int &count) {
    if (k == n) {
      if (sum == S) {
        count++;
      }
    } else {
      k++;
      for (int i = -1; i <= 1; i += 2) {
        sum += i == -1 ? -nums[k - 1] : nums[k - 1];
        backtracking(nums, S, k, n, sum, count);
        sum -= i == -1 ? -nums[k - 1] : nums[k - 1];
      }
    }
  }

public:
  int findTargetSumWays(vector<int> &nums, int S) {
    if (S > 1000)
      return 0;
    vector<vector<int>> D; //[n+1][1000]
    int n = nums.size();
    for (int j = 0; j < n + 1; j++) {
      vector<int> d(2000 + 1, 0);
      D.push_back(d);
    }
    D[0][1000 - S + 0] = 1;
    for (int j = 1; j < n + 1; j++) {
      for (int i = S - 1000; i <= S + 1000; i++) {
        if (i - nums[j - 1] >= S - 1000 && i - nums[j - 1] <= S + 1000) {
          D[j][1000 - S + i] += D[j - 1][1000 - S + i - nums[j - 1]];
        }
        if (i + nums[j - 1] >= S - 1000 && i + nums[j - 1] <= S + 1000) {
          D[j][1000 - S + i] += D[j - 1][1000 - S + i + nums[j - 1]];
        }
      }
    }
    return D[n][1000];
  }
};

int main() { return 0; }
