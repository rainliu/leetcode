#include <vector>
using namespace std;

class Solution {
private:
  void backtracking(vector<int> &nums, int target, int &count) {
    if (target < 0) {
      return;
    } else if (target == 0) {
      count++;
    } else {
      for (int i = 0; i < nums.size(); i++) {
        backtracking(nums, target - nums[i], count);
      }
    }
  }

public:
  int combinationSum4(vector<int> &nums, int target) {
    vector<int> D(target + 1);
    D[0] = 1;
    for (int i = 1; i <= target; i++) {
      int count = 0;
      for (int j = 0; j < nums.size(); j++) {
        if (i - nums[j] >= 0) {
          count += D[i - nums[j]];
        }
      }
      D[i] = count;
    }
    return D[target];
  }
};

int main() { return 0; }