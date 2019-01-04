#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minSubArrayLen(int s, vector<int> &nums) {
    int n = nums.size();
    int min_pos = 0;
    int min_len = n;
    int i = 0;
    int j = 0;
    int sum = 0;
    while (j < n) {
      sum += nums[j];
      while (i < j && sum - nums[i] >= s) {
        sum -= nums[i];
        i++;
      }
      if (sum >= s && j - i + 1 < min_len) {
        min_len = j - i + 1;
        min_pos = i;
      }
      j++;
    }
    if (sum >= s) {
      return min_len;
    } else {
      return 0;
    }
  }
};

int main() {
  Solution s;
  vector<int> nums = {2, 3, 1, 2, 4, 3};
  cout << s.minSubArrayLen(7, nums) << endl;
  cout << s.minSubArrayLen(4, nums) << endl;
  return 0;
}