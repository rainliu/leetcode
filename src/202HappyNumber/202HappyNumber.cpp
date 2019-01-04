#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool isHappy(int n) {
    unordered_map<int, bool> m;
    m[n] = true;
    while (n != 1) {
      int s = 0;
      while (n != 0) {
        int d = n % 10;
        n /= 10;
        s += d * d;
      }
      // cout << s << endl;
      if (m.find(s) != m.end()) {
        return false;
      } else {
        m[s] = true;
      }
      n = s;
    }
    return true;
  }
};

int main() {
  Solution s;
  cout << s.isHappy(19) << endl;
  cout << s.isHappy(0) << endl;
  cout << s.isHappy(1) << endl;
  cout << s.isHappy(1239223) << endl;
}