#include <iostream>
using namespace std;

class Solution {
private:
  int LUT[256];

private:
  int count1(int i) {
    int c = 0;
    for (int j = 0; j < 8; j++) {
      c += ((i >> j) & 0x1);
    }
    return c;
  }

public:
  Solution() {
    for (int i = 0; i < 256; i++) {
      LUT[i] = count1(i);
    }
  }
  int hammingWeight(uint32_t n) {
    uint8_t *b = (uint8_t *)(&n);
    int sum = 0;
    for (int i = 0; i < 4; i++) {
      sum += LUT[b[i]];
    }
    return sum;
  }
};

int main() {
  Solution s;
  cout << s.hammingWeight(11) << endl;
}