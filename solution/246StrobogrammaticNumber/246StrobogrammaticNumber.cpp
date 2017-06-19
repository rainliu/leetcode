#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool isStrobogrammatic(string num) {
    unordered_map<char, char> strob = {
        {'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
    int n = num.size();
    int lo = 0;
    int hi = n - 1;
    while (lo <= hi) {
      if (strob.find(num[lo]) == strob.end() || strob[num[lo]] != num[hi]) {
        return false;
      }
      lo++;
      hi--;
    }
    return true;
  }
};

int main() { return 0; }