#include <iostream>
#include <vector>
using namespace std;

/*
Hint:
How many majority elements could it possibly have?
*/
class Solution {
public:
  vector<int> majorityElement(vector<int> &nums) {
    int m = 0, n = 0, cm = 0, cn = 0;
    for (auto x : nums) {
      if (x == m) {
        cm++;
      } else if (x == n) {
        cn++;
      } else if (cm == 0) {
        m = x;
        cm = 1;
      } else if (cn == 0) {
        n = x;
        cn = 1;
      } else {
        cn--;
        cm--;
      }
    }
    cm = cn = 0;
    for (auto x : nums) {
      if (x == m) {
        cm++;
      } else if (x == n) {
        cn++;
      }
    }
    // cout << m << " " << n << endl;
    vector<int> result;
    if (cm > nums.size() / 3) {
      result.push_back(m);
    }
    if (cn > nums.size() / 3) {
      result.push_back(n);
    }
    return result;
  }
};

int main() {
  Solution s;
  vector<int> nums = {8, 8, 7, 7, 7};
  auto output = s.majorityElement(nums);
  cout << output[0] << " " << output[1] << endl;
  return 0;
}