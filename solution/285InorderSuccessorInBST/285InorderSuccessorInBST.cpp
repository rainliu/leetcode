#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  TreeNode *leftest(TreeNode *root) {
    if (root == nullptr) {
      return nullptr;
    } else if (root->left == nullptr) {
      return root;
    } else {
      return leftest(root->left);
    }
  }

  TreeNode *inorderSuccessorHelper(TreeNode *q, TreeNode *r, TreeNode *p) {
    if (r == p) {
      TreeNode *n = leftest(r->right);
      if (n != nullptr) {
        return n;
      } else {
        return q;
      }
    } else {
      if (r->left != nullptr) {
        TreeNode *n = inorderSuccessorHelper(r, r->left, p);
        if (n != nullptr) {
          return n;
        }
      }
      if (r->right != nullptr) {
        TreeNode *n = inorderSuccessorHelper(q, r->right, p);
        if (n != nullptr) {
          return n;
        }
      }
      return nullptr;
    }
  }

public:
  TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
    if (root == nullptr) {
      return nullptr;
    } else {
      return inorderSuccessorHelper(nullptr, root, p);
    }
  }
};

int main() { return 0; }
