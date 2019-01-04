#include <vector>
using namespace std;

class Solution {
private:
  vector<int> nums, idxs;

public:
  Solution(vector<int> nums) {
    this->nums = nums;
    for (int i = 0; i < nums.size(); i++) {
      idxs.push_back(i);
    }
    srand(nums.size());
  }

  /** Resets the array to its original configuration and return it. */
  vector<int> reset() {
    for (int i = 0; i < idxs.size(); i++) {
      idxs[i] = i;
    }
    return nums;
  }

  /** Returns a random shuffling of the array. */
  vector<int> shuffle() {
    for (int i = 0; i < idxs.size(); i++) {
      int j = rand() % (i + 1);
      swap(idxs[j], idxs[i]);
    }
    vector<int> result;
    for (int i = 0; i < idxs.size(); i++) {
      result.push_back(nums[idxs[i]]);
    }
    return result;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */