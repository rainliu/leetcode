#include <vector>
using namespace std;

class Solution {
private:
  unordered_map<int, int> m;
  vector<int> nums;

public:
  Solution(vector<int> nums) {
    this->nums = nums;
    for (int i = 0; i < nums.size(); i++) {
      m[nums[i]]++;
    }
    srand(nums.size());
  }

  int pick(int target) {
    int idx_m = rand() % m[target];
    int idx = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == target) {
        if (idx == idx_m) {
          return i;
        } else {
          idx++;
        }
      }
    }
    return 0;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */

int main() { return 0; }