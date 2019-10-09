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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        if(root==nullptr) return false;
        TreeNode* p = findNode(root, x);
        int count_left  = countTreeNodes(p->left);
        int count_right = countTreeNodes(p->right);
        int count_parent = n-1-count_left-count_right;
        return count_left>n-count_left ||
               count_right>n-count_right || 
              (p!=root && count_parent>n-count_parent);
    }
    
    int countTreeNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        return 1+countTreeNodes(root->left)+countTreeNodes(root->right);
    }
    
    TreeNode* findNode(TreeNode* root, int x){
        if(root==nullptr) return nullptr;
        if(root->val == x) return root;
        TreeNode* p = findNode(root->left, x);
        if(p==nullptr) p = findNode(root->right, x);
        return p;
    }
};
