#include <iostream>
#include <utility>
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
  pair<int, bool> countUnivalSubtreesHelper(TreeNode *root) {
    if (root == nullptr) {
      return make_pair(0, true);
    } else if (root->left == nullptr && root->right == nullptr) {
      return make_pair(1, true);
    } else if (root->left != nullptr && root->right == nullptr) {
      auto l = countUnivalSubtreesHelper(root->left);
      if (l.second && root->val == root->left->val) {
        return make_pair(1 + l.first, true);
      } else {
        return make_pair(l.first, false);
      }
    } else if (root->left == nullptr && root->right != nullptr) {
      auto r = countUnivalSubtreesHelper(root->right);
      if (r.second && root->val == root->right->val) {
        return make_pair(1 + r.first, true);
      } else {
        return make_pair(r.first, false);
      }
    } else {
      auto l = countUnivalSubtreesHelper(root->left);
      auto r = countUnivalSubtreesHelper(root->right);
      if (l.second && r.second && root->val == root->left->val &&
          root->val == root->right->val) {
        return make_pair(1 + l.first + r.first, true);
      } else {
        return make_pair(l.first + r.first, false);
      }
    }
  }

public:
  int countUnivalSubtrees(TreeNode *root) {
    auto r = countUnivalSubtreesHelper(root);
    return r.first;
  }
};

int main() { return 0; }