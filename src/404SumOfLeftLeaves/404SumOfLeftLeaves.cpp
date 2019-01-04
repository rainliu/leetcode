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
public:
  int sumOfLeftLeaves(TreeNode *root) {
    if (!root)
      return 0;
    int sum = 0;
    if (root->left != nullptr) {
      sum += !root->left->left && !root->left->right
                 ? root->left->val
                 : sumOfLeftLeaves(root->left);
    }
    if (root->right != nullptr) {
      sum += !root->right->left && !root->right->right
                 ? 0
                 : sumOfLeftLeaves(root->right);
    }
    return sum;
  }
};

int main() { return 0; }