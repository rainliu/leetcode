/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution2 {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1==nullptr && root2==nullptr) return true;
        if(root1==nullptr || root2==nullptr || root1->val != root2->val) return false;
        return (flipEquiv(root1->left, root2->left)&&flipEquiv(root1->right, root2->right)) ||
               (flipEquiv(root1->left, root2->right)&&flipEquiv(root1->right, root2->left));
    }    
};

class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        flip(root1);
        flip(root2);
        return sameTree(root1, root2);
    }
    
    void flip(TreeNode* root){
        if(root==nullptr) return;
        if(root->left==nullptr&root->right==nullptr) return;
        if(root->left==nullptr || (root->right!=nullptr && root->left->val > root->right->val)) {
            TreeNode* tmp = root->left;
            root->left = root->right;
            root->right = tmp;
        }
        flip(root->left);
        flip(root->right);
    }
    
    bool sameTree(TreeNode* root1, TreeNode* root2) {
        if(root1==nullptr&&root2==nullptr) return true;
        if(root1==nullptr&&root2!=nullptr) return false;
        if(root1!=nullptr&&root2==nullptr) return false;
        return root1->val==root2->val && sameTree(root1->left, root2->left) && sameTree(root1->right, root2->right);
    }
};
