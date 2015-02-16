#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

/*
Given a binary tree where all the right nodes are either leaf nodes with a sibling 
(a left node that shares the same parent node) or empty, flip it upside down and turn
it into a tree where the original right nodes turned into left leaf nodes. Return the new root.

For example:
Given a binary tree {1,2,3,4,5},
    1
   / \
  2   3
 / \
4   5
return the root of the binary tree [4,5,2,#,#,3,1].
   4
  / \
 5   2
    / \
   3   1  
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/

//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *upsideDownBinaryTree(TreeNode *root) {
    	if(root==NULL) return NULL;
    	
    	TreeNode *curr_left, *curr_right;
    	TreeNode *curr, *parent, *slibe;

    	parent = root;
    	slibe = root->right;
    	curr = root->left;
    	
    	root->left = root->right = NULL;

    	while(curr!=NULL){
	    	curr_left = curr->left;
	    	curr_right= curr->right;

	    	curr->left = slibe;
	    	curr->right= parent;

	    	parent = curr;
	    	slibe  = curr_right;
	    	curr   = curr_left;
	    }

	    return parent;
    }
};

int main(){
	Solution s;

	return 0;
} 