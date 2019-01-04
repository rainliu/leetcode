#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int> &nums) {
    vector<int> result;
    for (auto &x : nums) {
      --x;
    }
    int i = 0;
    while (i < nums.size()) {
      if (i != nums[i]) {
        if (nums[nums[i]] == nums[i]) {
          nums[i] = -1;
        } else {
          swap(nums[i], nums[nums[i]]);
        }
        if (nums[i] == -1) {
          ++i;
        }
      } else {
        ++i;
      }
    }
    for (i = 0; i < nums.size(); i++) {
      if (nums[i] == -1) {
        result.push_back(i + 1);
      }
    }
    return result;
  }
};

int main() { return 0; }