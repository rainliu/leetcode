#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        if(root==NULL) return result;

        stack<TreeNode *> preorder;
        preorder.push(root);
        do{
            root = preorder.top(); preorder.pop(); 
            result.push_back(root->val);
            if(root->right!=NULL) preorder.push(root->right);
            if(root->left!=NULL)  preorder.push(root->left);
        }while(!preorder.empty());
        return result;
    }

    vector<int> inorderTraversal(TreeNode *root) {
    	vector<int> result;
    	if(root==NULL) return result;

    	stack<TreeNode *> inorder;
    	unordered_map<TreeNode *, bool> visited; 
    	inorder.push(root);
    	do{
    		root = inorder.top(); 
    		if(visited.find(root)==visited.end()){
    			visited[root] = true;    		
	    		inorder.pop();
		    	if(root->right!=NULL) inorder.push(root->right);
		    	inorder.push(root);
		    	if(root->left!=NULL)  inorder.push(root->left);
		    }
		    else{
		    	result.push_back(root->val);
		    	inorder.pop();
		    }
	    }while(!inorder.empty());
    	return result;
    }
};

class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        if(root==NULL) return result;
        result.push_back(root->val);
        preorder(root->left, result);
        preorder(root->right,result);        
    }

    void preorder(TreeNode *root, vector<int> &result){
        if(root==NULL) return;
        result.push_back(root->val);
        preorder(root->left, result);
        preorder(root->right,result);
    }

    vector<int> inorderTraversal(TreeNode *root) {
    	vector<int> result;
    	if(root==NULL) return result;
    	inorder(root->left, result);
    	result.push_back(root->val);
    	inorder(root->right, result);
    	return result;
    }

    void inorder(TreeNode *root, vector<int> &result){
    	if(root==NULL) return;    	
    	inorder(root->left, result);
    	result.push_back(root->val);
    	inorder(root->right, result);
    }
};

int main(){
	Solution s;

	return 0;
}