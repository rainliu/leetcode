#include <iostream>
using namespace std;

class Solution {
public:
  string reverseString(string s) {
    int lo = 0;
    int hi = int(s.size()) - 1;
    while (lo < hi) {
      swap(s[lo++], s[hi--]);
    }
    return s;
  }
};

int main() { return 0; }