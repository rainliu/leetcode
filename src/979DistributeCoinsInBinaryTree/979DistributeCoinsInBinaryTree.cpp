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
    int distributeCoins(TreeNode* root) {
        int global = 0;
        post_order(root, global);
        return global;
    }
    
    int post_order(TreeNode* root, int& global) {
        if(root==nullptr) return 0;
        int l = post_order(root->left, global);
        int r = post_order(root->right, global);
        global += abs(l)+abs(r);
        return l+r+root->val-1;
    }
};
