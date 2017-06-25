#include <iostream>
using namespace std;

class Solution {
public:
  bool isPowerOfThree(int n) {
    int i = 1;
    while (i < n && i > 0) {
      cout << i << " ";
      i *= 3;
    }
    return i == n;
  }
};

int main() {
  Solution s;
  cout << s.isPowerOfThree(2147483647) << endl;
  return 0;
}