/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 
(a) Inorder (Left, Root, Right) : 4 2 5 1 3
(b) Preorder (Root, Left, Right) : 1 2 4 5 3
(c) Postorder (Left, Right, Root) : 4 5 2 3 1
 */
class Solution {
    unordered_map<int, int> pre_map;
    unordered_map<int, int> post_map;
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        for(int i=0; i<pre.size(); ++i){
            pre_map[pre[i]] = i;
            post_map[post[i]] = i;
        }
        return constructFromPrePost(pre, 0, int(pre.size())-1, post, 0, int(post.size())-1);
    }
    TreeNode* constructFromPrePost(vector<int>& pre, int pre_lo, int pre_hi,
                                   vector<int>& post,int post_lo,int post_hi) {
        if(pre_lo >pre_hi) return nullptr;
        if(pre_lo==pre_hi) return new TreeNode(pre[pre_lo]);
        
        TreeNode* root = new TreeNode(pre[pre_lo]);
        root->left  = constructFromPrePost(pre,  pre_lo+1, pre_map[post[post_hi-1]]-1, 
                                           post, post_lo,  post_map[pre[pre_lo+1]]);
        root->right = constructFromPrePost(pre,  pre_map[post[post_hi-1]],  pre_hi, 
                                           post, post_map[pre[pre_lo+1]]+1, post_hi-1);
        return root;
    }
};
