#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool isIsomorphic(string s, string t) {
    unordered_map<char, char> ms, mt;
    int n = s.size();
    for (int i = 0; i < n; i++) {
      if (ms.find(s[i]) == ms.end() && mt.find(t[i]) == mt.end()) {
        ms[s[i]] = t[i];
        mt[t[i]] = s[i];
      } else if (ms[s[i]] != t[i] || mt[t[i]] != s[i]) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution s;
  cout << s.isIsomorphic("ab", "aa") << endl;
  cout << s.isIsomorphic("ab", "cc") << endl;
  cout << s.isIsomorphic("egg", "add") << endl;
  cout << s.isIsomorphic("foo", "bar") << endl;
  cout << s.isIsomorphic("paper", "title") << endl;
}