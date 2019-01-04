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
  int maxDepth(TreeNode *root) {
    if (root == nullptr)
      return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
  }

public:
  int diameterOfBinaryTree(TreeNode *root) {
    if (root == nullptr)
      return 0;
    return max(max(maxDepth(root->left) + maxDepth(root->right),
                   diameterOfBinaryTree(root->left)),
               diameterOfBinaryTree(root->right));
  }
};

int main() { return 0; }