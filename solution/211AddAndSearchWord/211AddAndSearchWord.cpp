#include <iostream>
using namespace std;

struct Node {
  bool val;
  struct Node *child[26];
  Node() {
    val = false;
    for (int i = 0; i < 26; i++) {
      child[i] = nullptr;
    }
  }
};

class WordDictionary {
private:
  struct Node *root;

private:
  struct Node *addWordHelper(struct Node *x, string word, int d) {
    if (x == nullptr)
      x = new Node();
    if (d == word.size()) {
      x->val = true;
      return x;
    }
    x->child[word[d] - 'a'] =
        addWordHelper(x->child[word[d] - 'a'], word, d + 1);
    return x;
  }

  bool searchHelper(struct Node *x, string word, int d) {
    if (x == nullptr)
      return false;
    if (d == word.size()) {
      return x->val;
    } else {
      if (word[d] == '.') {
        bool val = false;
        for (int i = 0; i < 26; i++) {
          val = val || searchHelper(x->child[i], word, d + 1);
        }
        return val;
      } else {
        return searchHelper(x->child[word[d] - 'a'], word, d + 1);
      }
    }
  }

public:
  /** Initialize your data structure here. */
  WordDictionary() { root = new Node(); }
  ~WordDictionary() { delete root; }

  /** Adds a word into the data structure. */
  void addWord(string word) {
    if (word.size() == 0)
      return;
    root->child[word[0] - 'a'] =
        addWordHelper(root->child[word[0] - 'a'], word, 1);
  }

  /** Returns if the word is in the data structure. A word could contain the dot
   * character '.' to represent any one letter. */
  bool search(string word) {
    if (word.size() == 0)
      return false;
    return searchHelper(root, word, 0);
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */

int main() { return 0; }