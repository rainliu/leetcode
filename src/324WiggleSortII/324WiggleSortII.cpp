class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> result(nums);
        int n = nums.size();
        int mi = (n-1)>>1;
        int i=mi; 
        int j=n-1;
        int k=0;
        while(k<n){
            nums[k++] = result[i--];
            if(k<n){
                nums[k++] = result[j--];
            }
        }
    }
};

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  void wiggleSort(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> nums2(n);
    for (int i = 0; i < n; i++) {
      nums2[i] = nums[i];
    }
    int hi = n - 1;
    int lo = (n + 1) / 2 - 1;
    int k = 0;
    while (hi >= (n + 1) / 2) {
      nums[k++] = nums2[lo--];
      nums[k++] = nums2[hi--];
    }
    if (n % 2) {
      nums[k] = nums2[lo];
    }
  }
};

int main() {
  Solution s;
  vector<int> nums = {5, 3, 1, 2, 6, 7, 8, 5, 5};
  s.wiggleSort(nums);
  for (auto x : nums) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
