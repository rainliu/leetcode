#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int n = nums.size();
    for (int i = 1; i < n; i++) {
      for (int j = i; j > 0; j--) {
        if (nums[j] != 0 && nums[j - 1] == 0) {
          swap(nums[j], nums[j - 1]);
        } else {
          break;
        }
      }
    }
  }
};

int main() {
  Solution s;
  vector<int> nums = {0, 1, 0, 3, 12};
  s.moveZeroes(nums);
  for (auto x : nums) {
    cout << x << " ";
  }
  cout << endl;
}