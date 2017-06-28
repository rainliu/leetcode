#include <vector>
using namespace std;

class Solution {
public:
  int hIndex(vector<int> &citations) {
    int n = citations.size();
    vector<int> bucket(n + 1, 0);
    for (int i = 0; i < citations.size(); i++) {
      int c = citations[i];
      if (c >= n) {
        bucket[n]++;
      } else {
        bucket[c]++;
      }
    }
    int h = 0, sum = 0;
    for (int i = n; i >= 0; i--) {
      sum += bucket[i];
      if (sum >= i) {
        return i;
      }
    }
    return 0;
  }
};

int main() { return 0; }