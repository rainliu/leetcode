#include <iostream>
using namespace std;

class Solution {
  bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
  }

public:
  string reverseVowels(string s) {
    int lo = 0, hi = int(s.size()) - 1;
    while (lo < hi) {
      while (lo < hi && !isVowel(s[lo])) {
        ++lo;
      }
      while (lo < hi && !isVowel(s[hi])) {
        --hi;
      }
      if (lo < hi) {
        swap(s[lo++], s[hi--]);
      }
    }
    return s;
  }
};

int main() { return 0; }