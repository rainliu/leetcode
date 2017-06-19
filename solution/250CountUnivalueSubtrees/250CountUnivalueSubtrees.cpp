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
  vector<int> countUnivalSubtreesHelper(TreeNode *root) {
    if (root == nullptr) {
      return vector<int>{0, 1};
    } else if (root->left == nullptr && root->right == nullptr) {
      return vector<int>{1, 1};
    } else if (root->left != nullptr && root->right == nullptr) {
      auto l = countUnivalSubtreesHelper(root->left);
      if (l[1] && root->val == root->left->val) {
        return vector<int>{1 + l[0], 1};
      } else {
        return vector<int>{l[0], 0};
      }
    } else if (root->left == nullptr && root->right != nullptr) {
      auto r = countUnivalSubtreesHelper(root->right);
      if (r[1] && root->val == root->right->val) {
        return vector<int>{1 + r[0], 1};
      } else {
        return vector<int>{r[0], 0};
      }
    } else {
      auto l = countUnivalSubtreesHelper(root->left);
      auto r = countUnivalSubtreesHelper(root->right);
      if (l[1] && r[1] && root->val == root->left->val &&
          root->val == root->right->val) {
        return vector<int>{1 + l[0] + r[0], 1};
      } else {
        return vector<int>{l[0] + r[0], 0};
      }
    }
  }

public:
  int countUnivalSubtrees(TreeNode *root) {
    auto r = countUnivalSubtreesHelper(root);
    return r[0];
  }
};

int main() { return 0; }