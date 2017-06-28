#include <vector>
using namespace std;

class Solution {
public:
  int hIndex(vector<int> &citations) {
    int h = 0, n = citations.size();
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
      int mi = lo + (hi - lo) / 2;
      if (citations[mi] >= n - mi) {
        hi = mi - 1;
      } else {
        lo = mi + 1;
      }
    }
    return n - lo;
  }
};

int main() { return 0; }