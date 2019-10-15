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
    int findClosestLeaf(TreeNode* root, int k) {
        unordered_map<TreeNode*, unordered_set<TreeNode*>> m;
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        
        dfs(root, m);        
        
        auto it = find_if(m.begin(), m.end(), [=](const auto& p){ return p.first->val == k; });
        if(it!=m.end()){
            q.push(it->first);
            visited.insert(it->first);
        }
        while(!q.empty()){
            auto p = q.front(); q.pop();
            if(p->left==nullptr&&p->right==nullptr){
                return p->val;
            }else{
                for(const auto& r : m[p]){
                    if(visited.find(r) == visited.end()){
                        q.push(r);
                        visited.insert(r);
                    }
                }   
            }
        }
        return 0;
    }
    
    void dfs(TreeNode* root, unordered_map<TreeNode*, unordered_set<TreeNode*>>& m){
        if(root==nullptr) return;
        
        unordered_set<TreeNode*> s;        
        if(m.find(root)==m.end()){
            m.insert({root, s});   
        }
        
        if(root->left!=nullptr){
            m[root].insert(root->left);
            m[root->left].insert(root);
            dfs(root->left, m);
        }
        
        if(root->right!=nullptr){
            m[root].insert(root->right);
            m[root->right].insert(root);
            dfs(root->right, m);
        }
    }
};
