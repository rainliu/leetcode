#include <vector>
using namespace std;

class Solution {
public:
  int findDuplicateOn2(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
      int cand = nums[i];
      for (int j = i + 1; j < n; j++) {
        if (nums[j] == cand) {
          return cand;
        }
      }
    }
    return 0;
  }

  int findDuplicateOn(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      --nums[i];
    }
    int slow = n - 1, fast = n - 1;
    do {
      slow = nums[slow];
      fast = nums[nums[fast]];
    } while (slow != fast);
    fast = n - 1;
    do {
      slow = nums[slow];
      fast = nums[fast];
    } while (slow != fast);
    return slow + 1;
  }

  int findDuplicate(vector<int> &nums) {
    int n = nums.size();
    int slow = n - 1, fast = n - 1;
    do {
      slow = nums[slow] - 1;
      fast = nums[nums[fast] - 1] - 1;
    } while (slow != fast);
    fast = n - 1;
    do {
      slow = nums[slow] - 1;
      fast = nums[fast] - 1;
    } while (slow != fast);
    return slow + 1;
  }
};

int main() { return 0; }