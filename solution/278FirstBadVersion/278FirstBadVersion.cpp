#include <iostream>
using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) {
    if (isBadVersion(1)) {
      return 1;
    }
    int lo = 1;
    int hi = n;
    while (lo < hi) {
      if (hi - lo == 1 && !isBadVersion(lo) && isBadVersion(hi)) {
        return hi;
      } else {
        int mi = lo + (hi - lo) / 2;
        if (isBadVersion(mi)) {
          hi = mi;
        } else {
          lo = mi;
        }
      }
    }
    return lo;
  }
};

int main() { return 0; }