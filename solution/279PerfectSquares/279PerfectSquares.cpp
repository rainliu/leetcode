#include <iostream>
using namespace std;

// E[n] = min(E[n-i*i]+1)
class Solution {
public:
  int numSquares(int n) {
    vector<int> E(n + 1, n);
    E[0] = 0;
    for (int j = 1; j <= n; j++) {
      int i = 1;
      while (j - i * i >= 0) {
        E[j] = min(E[j], E[j - i * i] + 1);
        i++;
      }
    }
    return E[n];
  }
};

int main() { return 0; }