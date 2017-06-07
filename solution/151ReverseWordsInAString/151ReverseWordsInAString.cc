#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  void reverseWord(string &s, int lo, int hi) {
    while (lo <= hi) {
      auto tmp = s[lo];
      s[lo] = s[hi];
      s[hi] = tmp;
      lo++;
      hi--;
    }
  }
  void reverseWords(string &s) {
    int n = s.size();
    int i = 0;
    int j = n - 1;
    while (i <= j && s[i] == ' ') {
      i++;
    }
    while (i <= j && s[j] == ' ') {
      j--;
    }
    int l = i;
    int k = i;
    while (k <= j) {
      while (k <= j && s[k] != ' ') {
        k++;
      }
      reverseWord(s, l, k - 1);
      k++;
      while (k <= j && s[k] == ' ') {
        k++;
      }
      l = k;
    }
    reverseWord(s, i, j);
    k = 0;
    while (i <= j) {
      if (s[i] != ' ') {
        s[k] = s[i];
        i++;
      } else {
        s[k] = s[i];
        i++;
        while (i <= j && s[i] == ' ') {
          i++;
        }
      }
      k++;
    }
    s = s.substr(0, k);
  }
};

int main() {
  Solution s;
  string str = "  the   sky   is   blue  ";
  s.reverseWords(str);
  cout << str << endl;
}