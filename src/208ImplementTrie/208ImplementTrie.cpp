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

class Trie {
private:
  struct Node *root;

private:
  struct Node *insertHelper(struct Node *x, string word, int d) {
    if (x == nullptr)
      x = new Node();
    if (d == word.size()) {
      x->val = true;
      return x;
    }
    x->child[word[d] - 'a'] =
        insertHelper(x->child[word[d] - 'a'], word, d + 1);
    return x;
  }
  bool searchHelper(struct Node *x, string word, int d) {
    if (x == nullptr)
      return false;
    if (d == word.size())
      return x->val;
    return searchHelper(x->child[word[d] - 'a'], word, d + 1);
  }
  bool startsWithHelper(struct Node *x, string prefix, int d) {
    if (x == nullptr)
      return false;
    if (d == prefix.size())
      return true;
    return startsWithHelper(x->child[prefix[d] - 'a'], prefix, d + 1);
  }

public:
  /** Initialize your data structure here. */
  Trie() { root = new Node(); }
  ~Trie() { delete root; }

  /** Inserts a word into the trie. */
  void insert(string word) {
    if (word.size() == 0)
      return;
    root->child[word[0] - 'a'] =
        insertHelper(root->child[word[0] - 'a'], word, 1);
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    if (word.size() == 0)
      return false;
    return searchHelper(root->child[word[0] - 'a'], word, 1);
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) {
    if (prefix.size() == 0)
      return false;
    return startsWithHelper(root->child[prefix[0] - 'a'], prefix, 1);
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
int main() { return 0; }