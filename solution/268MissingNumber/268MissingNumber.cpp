#include <vector>
using namespace std;

class Solution {
public:
  int missingNumber(vector<int> &nums) {
    int n = nums.size();
    int i = 0;
    while (i < n) {
      if (nums[i] == i) {
        i++;
      } else if (nums[i] == n) {
        swap(nums[i], nums[n - 1]);
        n--;
      } else {
        swap(nums[i], nums[nums[i]]);
      }
    }
    return i;
  }
};

int main() { return 0; }