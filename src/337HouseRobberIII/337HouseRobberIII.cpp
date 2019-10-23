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
    int rob(TreeNode* root) {
        auto [s0, s1] = dfs(root);
        return max(s0, s1);
    }
    
    pair<int, int> dfs(TreeNode* root){
        if(root==nullptr) return {0, 0};       
        auto [l0, l1] = dfs(root->left);
        auto [r0, r1] = dfs(root->right);
        return {max(l0+r0, l1+r1+root->val), l0+r0};
    }
};
