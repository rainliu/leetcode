class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> D(nums.size(), 0);
        int global = 0;
        for(int j=0; j<nums.size(); ++j){
            int local = 0;
            for(int i=0; i<j; ++i){
                if(nums[i]<nums[j]){
                    local = max(local, D[i]);
                }
            }
            D[j]=1+local;
            global = max(global, D[j]);
        }
        return global;
    }
};

#include <vector>
using namespace std;

class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    vector<int> E(n, 0);
    int global = 0;
    for (int i = 0; i < n; i++) {
      int max_e = 0;
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {
          max_e = max(max_e, E[j]);
        }
      }
      E[i] = 1 + max_e;
      global = max(global, E[i]);
    }
    return global;
  }
};

int main() { return 0; }
