#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int shortestDistance1(vector<string> &words, string word1, string word2) {
    vector<int> pos1, pos2;
    int n = words.size();
    for (int i = 0; i < n; i++) {
      if (words[i] == word1) {
        pos1.push_back(i);
      } else if (words[i] == word2) {
        pos2.push_back(i);
      }
    }

    for (int i = 0; i < pos1.size(); i++) {
      for (int j = 0; j < pos2.size(); j++) {
        int d = abs(pos1[i] - pos2[j]);
        if (d == 1) {
          return 1;
        } else if (d < n) {
          n = d;
        }
      }
    }
    return n;
  }

  int shortestDistance(vector<string> &words, string word1, string word2) {
    int n = words.size();
    int global = n;
    int p1 = -1, p2 = -1;
    for (int i = 0; i < n; i++) {
      if (words[i] == word1) {
        p1 = i;
      }
      if (words[i] == word2) {
        p2 = i;
      }
      if (p1 != -1 && p2 != -1) {
        global = min(global, abs(p1 - p2));
      }
    }
    return global;
  }
};

int main() {
  vector<string> words = {"a", "a", "b", "b"};
  Solution s;
  cout << s.shortestDistance(words, "b", "a") << endl;
  return 0;
}