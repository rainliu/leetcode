#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int findMaxLengthTimeout(vector<int> &nums) {
    int n = nums.size();
    if (n == 0)
      return 0;
    vector<int> sum(n, 0);
    sum[0] = nums[0];
    for (int i = 1; i < n; i++) {
      sum[i] += sum[i - 1] + nums[i];
    }
    int global = 0;
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        // cout<<j-i+1<<" "<<sum[i]-nums[i]<<" "<<sum[j]<<endl;
        if ((j - i + 1) % 2 == 0 &&
            sum[j] - sum[i] + nums[i] == (j - i + 1) / 2) {
          global = max(global, j - i + 1);
        }
      }
    }
    return global;
  }

  int findMaxLength(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (nums[i] == 0)
        nums[i] = -1;
    }
    unordered_map<int, int> m;
    m[0] = -1;
    int sum = 0, global = 0;
    for (int i = 0; i < n; ++i) {
      sum += nums[i];
      if(m.find(sum)!=m.end()){
        global = max(global, i-m[sum]);
      }else{
        m[sum]=i;
      }
    }
    return global;
  }
};

int main() { return 0; }