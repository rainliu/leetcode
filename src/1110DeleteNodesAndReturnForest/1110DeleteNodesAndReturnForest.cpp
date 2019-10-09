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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> to_delete_set;
        for(int p : to_delete) {
            to_delete_set.insert(p);
        }
        return delNodesHelper(root, nullptr, false, to_delete_set);
    }
    
    vector<TreeNode*> delNodesHelper(TreeNode* root, TreeNode* parent, bool isLeft, unordered_set<int>& to_delete_set) {
        vector<TreeNode*> result;
        if (root==nullptr) return result;
        if (to_delete_set.find(root->val) != to_delete_set.end()) {
            if(parent!=nullptr) {
                if(isLeft) parent->left  = nullptr;
                else       parent->right = nullptr;
            }
        }else{
            if(parent==nullptr ||to_delete_set.find(parent->val)!=to_delete_set.end()){
                result.push_back(root);
            }
        }
        auto left_forest = delNodesHelper(root->left, root, true, to_delete_set);
        auto right_forest = delNodesHelper(root->right, root, false, to_delete_set);
        
        std::move(left_forest.begin(), left_forest.end(), std::back_inserter(result));    
        std::move(right_forest.begin(),right_forest.end(), std::back_inserter(result));
        
        return result;
    }
};
