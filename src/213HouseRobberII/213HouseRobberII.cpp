class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        return max(rob(nums, 0, n-2), rob(nums, 1,n-1));
    }
    
    int rob(vector<int>& nums, int lo, int hi){
        //D[i]=max(nums[i]+D[i-2], D[i-1])
        vector<int> D(3, 0);
        for(int i=lo; i<=hi; ++i){
            D[0]=max(nums[i]+D[2], D[1]);
            D[2]=D[1];
            D[1]=D[0];
        }
        return D[0];
    }
};

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
