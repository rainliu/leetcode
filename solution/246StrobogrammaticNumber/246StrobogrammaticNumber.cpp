#include <iostream>
using namespace std;

class Solution {
public:
  bool isStrobogrammatic(string num) {
    int n = num.size();
    unordered_map<char, char> strob;
    strob['0'] = '0';
    strob['1'] = '1';
    strob['6'] = '9';
    strob['8'] = '8';
    strob['9'] = '6';
    int lo = 0;
    int hi = n - 1;
    while (lo <= hi) {
      if (strob.find(num[lo]) == strob.end()) {
        return false;
      } else if (strob[num[lo]] != num[hi]) {
        return false;
      }
      lo++;
      hi--;
    }
    return true;
  }
};

int main() { return 0; }