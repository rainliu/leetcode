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
  int kthSmallestHelper(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    int leftCount = kthSmallestHelper(root->left);
    int rightCount = kthSmallestHelper(root->right);
    int count = leftCount + rightCount + 1;
    return count;
  }

public:
  int kthSmallest(TreeNode *root, int k) {
    while (root != nullptr) {
      int leftCount = kthSmallestHelper(root->left);
      if (k <= leftCount) {
        root = root->left;
      } else if (k == leftCount + 1) {
        return root->val;
      } else {
        root = root->right;
        k -= leftCount + 1;
      }
    }
    return 0;
  }
};

int main() { return 0; }