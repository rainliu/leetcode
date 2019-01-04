#include <iostream>
#include <vector>
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
    int global = 0;
    for (int k = 0; k < n; k++) {
      vector<int> E(n, 0);
      for (int i = (k + 2) % n; i != (k + 1) % n; i = (i + 1) % n) {
        E[i] = nums[i];
        int max = 0;
        for (int j = (k + 2) % n; j != i; j = (j + 1) % n) {
          if (j == (i - 1 + n) % n) {
            // do nothing
          } else if (max < E[j]) {
            max = E[j];
          }
        }
        E[i] += max;
      }
      global = max(E[k], global);
    }
    return global;
  }
};

int main() {}