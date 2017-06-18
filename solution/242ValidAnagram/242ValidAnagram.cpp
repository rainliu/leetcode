#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool isAnagram1(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
  }
  bool isAnagram(string s, string t) {
    unordered_map<char, int> m;
    for (auto &c : s) {
      if (m.find(c) == m.end()) {
        m[c] = 1;
      } else {
        m[c] = m[c] + 1;
      }
    }
    for (auto &c : t) {
      if (m.find(c) == m.end()) {
        return false;
      } else {
        if (m[c] == 0) {
          return false;
        } else {
          m[c] = m[c] - 1;
        }
      }
    }
    for (auto &p : m) {
      if (p.second != 0) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution s;
  cout << s.isAnagram("anagram", "nagaram") << endl;
  cout << s.isAnagram("anagramb", "nagaram") << endl;
  cout << s.isAnagram("rat", "car") << endl;
  return 0;
}