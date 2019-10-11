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
    if (!root || root == p || root == q) {
      return root;
    }
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    return !left ? right : (!right ? left : root);
  }
};


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
        if(root->val==p->val || root->val==q->val) return root;
        bool left = lowestCommonAncestorHelper(root->left, p, q);
        bool right = lowestCommonAncestorHelper(root->right, p, q);
        if(left && right) return root;
        else if(left) return lowestCommonAncestor(root->left, p, q);
        else return lowestCommonAncestor(root->right, p, q);
    }
    
    bool lowestCommonAncestorHelper(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==nullptr) return false;
        return root->val==p->val || 
            root->val==q->val || 
            lowestCommonAncestorHelper(root->left, p, q) ||
            lowestCommonAncestorHelper(root->right, p, q);
    }
};
int main() { return 0; }
