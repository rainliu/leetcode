#include <algorithm>
#include <iostream>
#include <limits>
#include <unordered_map>
#include <vector>
using namespace std;

class WordDistance {
private:
  unordered_map<string, vector<int>> m;

public:
  WordDistance(vector<string> words) {
    for (int i = 0; i < words.size(); i++) {
      if (m.find(words[i]) == m.end()) {
        m[words[i]] = vector<int>{i};
      } else {
        m[words[i]].push_back(i);
      }
    }
  }

  int shortest(string word1, string word2) {
    auto p1 = m[word1].begin();
    auto p2 = m[word2].begin();
    int global = numeric_limits<int>::max();
    while (p1 != m[word1].end() && p2 != m[word2].end()) {
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
    return global;
  }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */
int main() {
  vector<string> words = {"a", "a", "b", "b"};
  WordDistance s(words);
  cout << s.shortest("b", "a") << endl;
  return 0;
}