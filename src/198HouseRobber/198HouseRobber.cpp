#include <iostream>
using namespace std;

class Solution {
public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    if (n == 0) {
      return 0;
    } else if (n == 1) {
      return nums[0];
    }
    vector<int> E(n, 0);
    for (int i = 0; i < n; i++) {
      E[i] = nums[i];
      int max = 0;
      for (int j = 0; j < i - 1; j++) {
        if (max < E[j]) {
          max = E[j];
        }
      }
      E[i] += max;
    }
    return E[n - 1] > E[n - 2] ? E[n - 1] : E[n - 2];
  }
};

int main() {}