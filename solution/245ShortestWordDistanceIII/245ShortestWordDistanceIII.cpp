#include <algorithm>
#include <iostream>
#include <limits>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int shortestWordDistance(vector<string> &words, string word1, string word2) {
    vector<int> pos1, pos2;
    int n = words.size();
    for (int i = 0; i < n; i++) {
      if (words[i] == word1) {
        pos1.push_back(i);
      } else if (words[i] == word2) {
        pos2.push_back(i);
      }
    }
    int global = n;
    if (word1 == word2) {
      for (int i = 1; i < pos1.size(); i++) {
        global = min(global, pos1[i] - pos1[i - 1]);
      }
    } else {
      auto p1 = pos1.begin();
      auto p2 = pos2.begin();
      while (p1 != pos1.end() && p2 != pos2.end()) {
        int d = abs(*p1 - *p2);
        if (d < global) {
          global = d;
        }
        if (*p1 < *p2) {
          p1++;
        } else {
          p2++;
        }
      }
    }
    return global;
  }
};

int main() {
  vector<string> words = {"a", "a", "b", "b"};
  Solution s;
  cout << s.shortestWordDistance(words, "b", "a") << endl;
  return 0;
}