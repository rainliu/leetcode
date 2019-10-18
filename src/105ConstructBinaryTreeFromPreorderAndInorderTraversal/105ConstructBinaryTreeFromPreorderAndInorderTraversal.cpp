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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> preorder_map;
        unordered_map<int, int> inorder_map;
        for(int i=0; i<preorder.size(); ++i){
            preorder_map[preorder[i]] = i;
            inorder_map[inorder[i]] = i;
        }
        return buildTree(preorder, preorder_map, 0, int(preorder.size())-1, 
                         inorder,  inorder_map,  0, int(inorder.size())-1);
    }
    
    TreeNode* buildTree(vector<int>& preorder, unordered_map<int, int>& preorder_map, int pre_lo, int pre_hi, 
                        vector<int>& inorder,  unordered_map<int, int>& inorder_map,  int in_lo,  int in_hi){
        if(pre_lo > pre_hi) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[pre_lo]);
        
        int mi = inorder_map[preorder[pre_lo]]-in_lo;
        root->left  = buildTree(preorder, preorder_map, pre_lo+1, pre_lo+mi,
                                inorder,  inorder_map,  in_lo, in_lo+mi-1);
        root->right = buildTree(preorder, preorder_map, pre_lo+mi+1, pre_hi, 
                                inorder,  inorder_map,  in_lo+mi+1, in_hi);
        return root;
    }
};

#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree
*/

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    	int size = preorder.size();
    	if(size==0) return nullptr;

        for(int i=0; i<size; i++){
        	preorder_map[preorder[i]] = i;
        	inorder_map[inorder[i]] = i;
        }

        return build(preorder, 0, size-1, inorder, 0, size-1);
    }

    TreeNode *build(vector<int> &preorder, int pre_lo, int pre_hi, vector<int> &inorder, int in_lo, int in_hi) {
    	if(pre_lo<=pre_hi&&in_lo<=in_hi){
	    	TreeNode *root = new TreeNode(preorder[pre_lo]);
	    	int bp, ep, bi, ei;    

	        bi = in_lo;
	        ei = inorder_map[preorder[pre_lo]]-1;
	        bp = pre_lo+1;
	        ep = ei<in_lo?pre_lo:pre_lo+1+ei-bi;
	        root->left = build(preorder, bp, ep, inorder, bi, ei);

			bp =(ei<in_lo?pre_lo:pre_lo+1+ei-bi)+1;
	        ep = pre_hi;
	        bi = inorder_map[preorder[pre_lo]]+1;
	        ei = in_hi;	        
	        root->right= build(preorder, bp, ep, inorder, bi, ei);

	        return root;
	    }else{
	    	return nullptr;
	    }
    }


private:
	unordered_map<int, int> preorder_map, inorder_map;        
};

int main(){
	return 0;
}
