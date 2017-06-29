#include <iostream>
using namespace std;

class Solution {
public:
  int totalHammingDistance(vector<int> &nums) {
    int n = nums.size();
    int pq[32][2];
    memset(pq, 0, sizeof(pq));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 32; ++j) {
        pq[j][(nums[i] >> j) & 0x1]++;
      }
    }
    int sum = 0;
    for (int j = 0; j < 32; ++j) {
      sum += pq[j][0] * pq[j][1];
    }
    return sum;
  }
};

int main() { return 0; }