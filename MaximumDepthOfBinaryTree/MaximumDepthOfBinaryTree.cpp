#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#define MAX(a, b) ((a)>(b) ? (a) : (b))

class Solution {
public:
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