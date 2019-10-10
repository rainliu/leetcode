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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int,set<int>>> m;
        queue<tuple<int,int,TreeNode*>> q;
        if(root!=nullptr) q.push({0,0,root});
        while(!q.empty()){
            auto [x, y, root] = q.front(); q.pop();
            
            m[x][y].insert(root->val);
            if(root->left!=nullptr) q.push({x-1, y+1, root->left});
            if(root->right!=nullptr) q.push({x+1, y+1, root->right});
        }
        
        vector<vector<int>> results;
        for(auto& x: m){
            vector<int> result;
            for(auto& y: x.second){
                for(auto v: y.second){
                    result.push_back(v);
                }
            }
            results.push_back(result);
        }
        
        return results;
    }
};
