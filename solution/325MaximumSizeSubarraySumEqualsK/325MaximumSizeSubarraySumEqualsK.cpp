#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int maxSubArrayLenOn2(vector<int> &nums, int k) {
    int n = nums.size(), global = 0;
    for (int i = 0; i < n; i++) {
      int sum = 0;
      for (int j = i; j < n; j++) {
        sum += nums[j];
        if (sum == k) {
          global = max(global, j - i + 1);
        }
      }
    }
    return global;
  }

  int maxSubArrayLen(vector<int> &nums, int k) {
    unordered_map<int, int> m;
    int n = nums.size(), global = 0;
    m[0] = -1;
    for (int i = 0; i < n; i++) {
      if (i - 1 >= 0) {
        nums[i] += nums[i - 1];
      }
      if (m.find(nums[i]) == m.end()) {
        m[nums[i]] = i;
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      if (m.find(nums[i] - k) != m.end()) {
        global = max(global, i - m[nums[i] - k]);
        // cout<<global<<"("<<i<<" "<<m[nums[i] - k] <<" "<<nums[i] - k<<")";
      }
    }
    return global;
  }
};

int main() {
  Solution s;
  vector<int> nums = {
      -84, -87, -78, -16, -94, -36, -87, -93, -50, -22, -63, -28,  -91,
      -60, -64, -27, -41, -27, -73, -37, -12, -69, -68, -30, -83,  -31,
      -63, -24, -68, -36, -30, -3,  -23, -59, -70, -68, -94, -57,  -12,
      -43, -30, -74, -22, -20, -85, -38, -99, -25, -16, -71, -14,  -27,
      -92, -81, -57, -74, -63, -71, -97, -82, -6,  -26, -85, -28,  -37,
      -6,  -47, -30, -14, -58, -25, -96, -83, -46, -15, -68, -35,  -65,
      -44, -51, -88, -9,  -77, -79, -89, -85, -4,  -52, -55, -100, -33,
      -61, -77, -69, -40, -13, -27, -87, -95, -40};

  cout << s.maxSubArrayLenTimeout(nums, 105) << endl;
  return 0;
}