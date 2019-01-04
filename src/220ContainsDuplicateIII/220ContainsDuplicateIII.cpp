#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
    int n = nums.size();
    set<int64_t> s;
    int j = 0;
    for (int i = 0; i < n; i++) {
      if (i - j > k)
        s.erase(nums[j++]);
      auto a = s.lower_bound(int64_t(nums[i]) - t);
      if (a != s.end() && abs(*a - nums[i]) <= t) {
        return true;
      }
      s.insert(nums[i]);
    }
    return false;
  }
};