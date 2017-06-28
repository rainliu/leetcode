#include <iostream>
using namespace std;
/**
 * Definition for a binary tree node.
 */ struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  bool isSameTree(TreeNode *s, TreeNode *t) {
    if (s == nullptr && t == nullptr) {
      return true;
    } else if ((!s && t) || (s && !t)) {
      return false;
    } else {
      return s->val == t->val && isSameTree(s->left, t->left) &&
             isSameTree(s->right, t->right);
    }
  }

public:
  bool isSubtree(TreeNode *s, TreeNode *t) {
    if (s == nullptr || t == nullptr) {
      return false;
    }
    return isSameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
  }
};

int main() { return 0; }