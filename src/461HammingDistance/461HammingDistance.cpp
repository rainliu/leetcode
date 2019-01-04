#include <iostream>
using namespace std;

class Solution {
public:
  int hammingDistance(int x, int y) {
    static int LUT[] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};
    int c = 0;
    for (int z = x ^ y; z != 0; z >>= 4) {
      c += LUT[z & 0xF];
    }
    return c;
  }
};

int main() { return 0; }