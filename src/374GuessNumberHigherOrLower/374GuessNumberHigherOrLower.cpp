#include <iostream>
using namespace std;

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return
// 0
int guess(int num);

class Solution {
public:
  int guessNumber(int n) {
    int lo = 1, hi = n;
    while (lo <= hi) {
      int mi = lo + (hi - lo) / 2;
      if (guess(mi) == 0) {
        return mi;
      } else if (guess(mi) > 0) {
        lo = mi + 1;
      } else {
        hi = mi - 1;
      }
    }
    return 0;
  }
};

int main() { return 0; }