/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val) return lowestCommonAncestor(root, q, p);
        if(q->val < root->val) return lowestCommonAncestor(root->left, p, q);
        if(root->val < p->val) return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};


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
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (p->val > q->val) {
      TreeNode *t = p;
      p = q;
      q = t;
    }
    while (root != nullptr) {
      if (p->val == root->val || q->val == root->val) {
        return root;
      } else if (q->val < root->val) {
        root = root->left;
      } else if (p->val > root->val) {
        root = root->right;
      } else {
        return root;
      }
    }
    return nullptr;
  }
};

int main() { return 0; }
