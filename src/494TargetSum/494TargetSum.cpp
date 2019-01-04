#include <vector>
using namespace std;

class Solution {
private:
  void backtracking(vector<int> &nums, int S, int k, int n, int sum,
                    int &count) {
    if (k == n) {
      if (sum == S) {
        count++;
      }
    } else {
      k++;
      for (int i = -1; i <= 1; i += 2) {
        sum += i == -1 ? -nums[k - 1] : nums[k - 1];
        backtracking(nums, S, k, n, sum, count);
        sum -= i == -1 ? -nums[k - 1] : nums[k - 1];
      }
    }
  }

public:
  int findTargetSumWays(vector<int> &nums, int S) {
    if (S > 1000)
      return 0;
    vector<vector<int>> D; //[n+1][1000]
    int n = nums.size();
    for (int j = 0; j < n + 1; j++) {
      vector<int> d(2000 + 1, 0);
      D.push_back(d);
    }
    D[0][1000 - S + 0] = 1;
    for (int j = 1; j < n + 1; j++) {
      for (int i = S - 1000; i <= S + 1000; i++) {
        if (i - nums[j - 1] >= S - 1000 && i - nums[j - 1] <= S + 1000) {
          D[j][1000 - S + i] += D[j - 1][1000 - S + i - nums[j - 1]];
        }
        if (i + nums[j - 1] >= S - 1000 && i + nums[j - 1] <= S + 1000) {
          D[j][1000 - S + i] += D[j - 1][1000 - S + i + nums[j - 1]];
        }
      }
    }
    return D[n][1000];
  }
};

int main() { return 0; }