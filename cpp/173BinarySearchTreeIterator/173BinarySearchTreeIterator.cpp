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
Implement an iterator over a binary search tree (BST). 
Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, 
where h is the height of the tree.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        if(root==NULL) return;

        min_stack.push(root);
        while(root->left!=NULL){
       		root = root->left;
       		min_stack.push(root);
      	}
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !min_stack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *root = min_stack.top(); min_stack.pop();
        int result = root->val;

        if(root->right!=NULL){
        	root = root->right;
        	min_stack.push(root);
        	while(root->left!=NULL){
	       		root = root->left;
	       		min_stack.push(root);
	      	}
        }

        return result;  
    }
private:
	stack<TreeNode *> min_stack;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

 int main(){

 	return 0;
 }