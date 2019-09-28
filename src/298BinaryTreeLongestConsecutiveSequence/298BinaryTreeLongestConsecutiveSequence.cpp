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
    int longestConsecutive(TreeNode* root) {
        int global = 0;
        longestConsecutiveHelper(root, global);
        return global;
    }
    
    int longestConsecutiveHelper(TreeNode* root, int& global) {
        if (root==nullptr) return 0;
        int left = longestConsecutiveHelper(root->left, global) + 1;
        int right = longestConsecutiveHelper(root->right, global) + 1;
        if (root->left!=nullptr && root->val+1 != root->left->val) {
            left = 1;
        }
        if (root->right!=nullptr && root->val+1 != root->right->val) {
            right = 1;
        }
        int local = max(left, right);
        global = max(global, local);
        return local;
    }
};

class Solution2 {
public:
    int longestConsecutive(TreeNode* root) {
        return longestConsecutiveHelper(root, nullptr, 0);
    }
    
    int longestConsecutiveHelper(TreeNode* root, TreeNode* parent, int len) {
        if (root==nullptr) return 0;
        len = (parent!=nullptr && root->val == parent->val+1) ? len+1 : 1;
        return max(max(len, longestConsecutiveHelper(root->left, root, len)), longestConsecutiveHelper(root->right, root, len));
    }
};
