#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int longestSubstring(string s, int k) {
    unordered_map<char, pair<int, int>> m;
    for (int i = 0; i < s.size(); i++) {
      if (m.find(s[i]) == m.end()) {
        m[s[i]] = make_pair(i, 1);
      } else {
        auto p = m[s[i]];
        p.second++;
        m[s[i]] = p;
      }
    }
    int j = s.size();
    for (auto &p : m) {
      if (p.second.second < k) {
        j = p.second.first;
        break;
      }
    }
    // cout<<j<<" ";
    if (j == s.size())
      return j;
    int left = j < k ? 0 : longestSubstring(s.substr(0, j), k);
    int right =
        (int(s.size()) - j - 1) < k
            ? 0
            : longestSubstring(s.substr(j + 1, int(s.size()) - j - 1), k);
    return max(left, right);
  }
};

int main() { return 0; }