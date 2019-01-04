#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
  int partition(vector<int> &nums, int lo, int hi) {
    int pilot_no = lo;
    int pilot = nums[lo];
    int k = lo + 1;
    while (k < hi) {
      if (nums[k] < pilot) {
        lo++;
        swap(nums[lo], nums[k]);
        k++;
      } else {
        hi--;
        swap(nums[k], nums[hi]);
      }
    }
    swap(nums[pilot_no], nums[lo]);
    return lo;
  }

public:
  int findKthLargest(vector<int> &nums, int k) {
    int lo = 0;
    int hi = nums.size();
    k = hi - k;
    while (lo < hi) {
      int pilot = partition(nums, lo, hi);
      if (pilot == k) {
        return nums[k];
      } else if (pilot < k) {
        lo = pilot + 1;
      } else {
        hi = pilot;
      }
    }
  }
};

int main() {
  Solution s;
  vector<int> nums1 = {3, 2, 1, 5, 6, 4};
  cout << s.findKthLargest(nums1, 4) << endl;
  vector<int> nums2 = {1, 1, 2, 3, 4, 5, 5, 5};
  cout << s.findKthLargest(nums2, 4) << endl;
  return 0;
}