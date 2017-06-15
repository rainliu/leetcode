#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++) {
      if (m.find(nums[i]) != m.end()) {
        int j = m[nums[i]];
        if (abs(j - i) <= k) {
          return true;
        }
      }
      m[nums[i]] = i;
    }
    return false;
  }
};

int main() { return 0; }