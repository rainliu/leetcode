#include <vector>
using namespace std;

class Solution {
public:
  vector<string> summaryRanges(vector<int> &nums) {
    int n = nums.size();
    if (n == 0) {
      return vector<string>{};
    }
    vector<string> result;
    int i = 0;
    int j = 1;
    int diff = 0;
    while (j <= n) {
      if (j < n) {
        diff = nums[j] - nums[j - 1] - 1;
      } else {
        diff = 1;
      }
      if (diff != 0) {
        if (j - i == 1) {
          result.push_back(to_string(nums[i]));
        } else {
          result.push_back(to_string(nums[i]) + "->" + to_string(nums[j - 1]));
        }
        i = j;
      }
      j++;
    }
    return result;
  }
};

int main() { return 0; }