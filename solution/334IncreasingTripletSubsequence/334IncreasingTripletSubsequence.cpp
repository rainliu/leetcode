#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool increasingTripletTimeOut(vector<int> &nums) {
    int n = nums.size();
    vector<int> E(n, 0);
    for (int i = 0; i < n; i++) {
      int e = 0;
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {
          e = max(e, E[j]);
        }
      }
      E[i] = e + 1;
    }
    int e = 0;
    for (int i = 0; i < n; i++) {
      e = max(e, E[i]);
    }
    return e >= 3;
  }

  bool increasingTriplet(vector<int> &nums) {
    int small = numeric_limits<int>::max();
    int big = numeric_limits<int>::max();
    for (auto x : nums) {
      if (x <= small) {
        small = x;
      } else if (x <= big) {
        big = x;
      } else {
        return true;
      }
    }
    return false;
  }
};

int main() { return 0; }