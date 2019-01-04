#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int firstUniqChar(string s) {
    int n = s.size();
    unordered_map<char, int> m;
    for (int i = 0; i < n; i++) {
      if (m.find(s[i]) == m.end()) {
        m[s[i]] = i;
      } else {
        m[s[i]] = n;
      }
    }
    int global = n;
    for (auto p : m) {
      global = min(global, p.second);
    }
    return global == n ? -1 : global;
  }
};

int main() { return 0; }