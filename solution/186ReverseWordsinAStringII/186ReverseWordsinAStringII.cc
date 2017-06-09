#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
  void reverseWords(string &s) {
    int n = int(s.size());
    int i = 0;
    int j = 0;
    while (j < n) {
      if ((j + 1 < n && s[j + 1] == ' ') || j + 1 == n) {
        reverse(s.begin() + i, s.begin() + j + 1);
        j++;
        i = j + 1;
      }
      j++;
    }
    reverse(s.begin(), s.end());
  }
};

int main() {
  Solution s;
  string str = "the sky is blue";
  s.reverseWords(str);
  cout << str;
  return 0;
}
