#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> productExceptSelf1(vector<int> &nums) {
    int n = nums.size();
    vector<int> L(n, 1);
    vector<int> R(n, 1);
    for (int i = 1; i < n; i++) {
      L[i] = L[i - 1] * nums[i - 1];
    }
    for (int i = n - 2; i >= 0; i--) {
      R[i] = R[i + 1] * nums[i + 1];
    }
    vector<int> result(n);
    for (int i = 0; i < n; i++) {
      result[i] = L[i] * R[i];
    }
    return result;
  }

  vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size();
    vector<int> result(n, 1);
    for (int i = 1; i < n; i++) {
      result[i] = result[i - 1] * nums[i - 1];
    }
    int R = 1;
    for (int i = n - 2; i >= 0; i--) {
      R = R * nums[i + 1];
      result[i] *= R;
    }
    return result;
  }
};

int main() {}