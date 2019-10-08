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
    bool isCompleteTree(TreeNode* root) {
        if(root==nullptr) return true;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        int pre = 0;
        while(!q.empty()){
            auto p = q.front();
            TreeNode* root = p.first;
            int position = p.second;
            if(position!=pre+1) return false;
            pre = position;
            q.pop();
            
            if(root->left!=nullptr){
                q.push({root->left, position*2});
            }
            if(root->right!=nullptr){
                q.push({root->right, position*2+1});
            }
        }
        return true;
    }
    
};
