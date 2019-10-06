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
    bool isUnivalTree(TreeNode* root) {
        return isUnivalTree(root, root);
    }
    bool isUnivalTree(TreeNode* root, TreeNode* parent) {
        if(root==nullptr) return true;
        return root->val==parent->val&&isUnivalTree(root->left, root)&&isUnivalTree(root->right, root);
    }
};
