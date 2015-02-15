#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/

//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#define MIN(a, b) ((a)<(b) ? (a) : (b))

class Solution {
public:
    int minDepth(TreeNode *root) {
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return 1;
        int left  = root->left  ? minDepth(root->left)  : numeric_limits<int>::max();
        int right = root->right ? minDepth(root->right) : numeric_limits<int>::max();

        return 1 + MIN(left, right);
    }
};

int main(){
	Solution s;

	return 0;
} 