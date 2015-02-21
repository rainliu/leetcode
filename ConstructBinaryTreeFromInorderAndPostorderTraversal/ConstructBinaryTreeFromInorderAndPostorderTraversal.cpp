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
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    	int size = inorder.size();
    	if(size==0) return nullptr;

        for(int i=0; i<size; i++){
        	postorder_map[postorder[i]] = i;
        	inorder_map[inorder[i]] = i;
        }

        return build(inorder, 0, size-1, postorder, 0, size-1);
    }

    TreeNode *build(vector<int> &inorder, int in_lo, int in_hi, vector<int> &postorder, int post_lo, int post_hi) {
    	if(post_lo<=post_hi&&in_lo<=in_hi){
	    	TreeNode *root = new TreeNode(postorder[post_hi]);
	    	int bp, ep, bi, ei;    

	        bi = in_lo;
	        ei = inorder_map[postorder[post_hi]]-1;
	        bp = post_lo;
	        ep = ei<in_lo?post_lo-1:post_lo+ei-bi;
	        root->left = build(inorder, bi, ei, postorder, bp, ep);

			bp =(ei<in_lo?post_lo-1:post_lo+ei-bi)+1;
	        ep = post_hi-1;
	        bi = inorder_map[postorder[post_hi]]+1;
	        ei = in_hi;	        
	        root->right= build(inorder, bi, ei, postorder, bp, ep);

	        return root;
	    }else{
	    	return nullptr;
	    }
    }
    
private:
	unordered_map<int, int> postorder_map, inorder_map;        
};

int main(){
	return 0;
}