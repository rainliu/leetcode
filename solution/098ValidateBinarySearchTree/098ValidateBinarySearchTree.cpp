#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
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
    bool isValidBST(TreeNode *root) {
    	return isValid(root, NULL, NULL);
    }

    bool isValid(TreeNode *root, int* left, int* right){
    	if(root==NULL) return true;

    	if (!( (left!=NULL ?root->val > *left: true) && 
    		   (right!=NULL?root->val < *right:true)
    		 )
    	   ){
    		return false;
    	}
    	return isValid(root->left, left,  &root->val) && 
    		   isValid(root->right,&root->val, right);
    }
};

class Solution2 {
public:
    bool isValidBST(TreeNode *root) {
    	prev = NULL;
    	return inOrder(root);
    }

    bool inOrder(TreeNode *root){
    	if(root==NULL) return true;
    	
    	bool result = true;

    	if(root->left!=NULL) result = result && inOrder(root->left);

    	if(prev!=NULL){
    		result = result && (root->val > prev->val);
    	}
    	prev = root;

    	if(root->right!=NULL) result = result && inOrder(root->right);
    
    	return result;
    }
private:
	TreeNode *prev;
};


int main(){
	Solution2 s;

	TreeNode root(1);
	TreeNode left(1);
	root.left = &left;

	cout << s.isValidBST(&root) <<endl;
	
	return 0;
} 