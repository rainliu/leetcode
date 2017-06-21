#include <iostream>
using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) {
    int lo = 1;
    int hi = n;
    while (lo < hi) {
      int mi = lo + (hi - lo) / 2;
      if (isBadVersion(mi)) {
        hi = mi;
      } else {
        lo = mi + 1;
      }
    }
    return lo;
  }
};

int main() { return 0; }