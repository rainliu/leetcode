#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree 
in which the depth of the two subtrees of every node never differ by more than 1.
*/

//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#define MIN(a, b) ((a)<(b) ? (a) : (b))
#define MAX(a, b) ((a)>(b) ? (a) : (b))

class Solution {
public:
    bool isBalanced(TreeNode *root) {
    	if(root==NULL) return true;

    	return abs(maxDepth(root->left)-maxDepth(root->right)) <= 1 &&
    		isBalanced(root->left) && isBalanced(root->right);
    }

    int maxDepth(TreeNode *root) {
        if(root==NULL) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return 1 + MAX(left, right);
    }
};


int main(){
	Solution s;

	return 0;
} 