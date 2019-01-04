#include <iostream>
#include <stack>
using namespace std;

/**
 * Definition for binary tree
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
  stack<TreeNode *> s;

public:
  BSTIterator(TreeNode *root) {
    while (root != nullptr) {
      s.push(root);
      root = root->left;
    }
  }

  /** @return whether we have a next smallest number */
  bool hasNext() { return !s.empty(); }

  /** @return the next smallest number */
  int next() {
    auto p = s.top();
    s.pop();
    auto q = p->right;
    while (q != nullptr) {
      s.push(q);
      q = q->left;
    }
    return p->val;
  }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

int main() { return 0; }
