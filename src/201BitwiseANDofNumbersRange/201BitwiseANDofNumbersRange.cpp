#include <iostream>
using namespace std;

class Solution {
private:
  int msb(int k) {
    for (int i = 31; i >= 0; i--) {
      if (k & (1 << i)) {
        return i;
      }
    }
    return 0;
  }

public:
  int rangeBitwiseAnd(int m, int n) {
    if (msb(m) != msb(n)) {
      return 0;
    } else if (m == n) {
      return m & n;
    }
    int r = ~((1 << (msb(m ^ n) + 1)) - 1);
    return r & m;
  }
};

int main() {
  Solution s;
  cout << s.rangeBitwiseAnd(5, 5) << endl;
  cout << s.rangeBitwiseAnd(5, 7) << endl;
  cout << s.rangeBitwiseAnd(10, 11) << endl;
}