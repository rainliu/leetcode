#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

/*
https://oj.leetcode.com/problems/binary-tree-maximum-path-sum/

Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
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
    int maxPathSum(TreeNode *root) {
        global = numeric_limits<int>::min();
        findMaxPath(root);
        return global;
    }
    
    int findMaxPath(TreeNode *root){
        if(root==nullptr) return 0;
        int left =findMaxPath(root->left);
        int right=findMaxPath(root->right);
        int local = max(max(max(root->val, root->val+left), root->val+right), root->val+left+right);
        global = max(global, local);
        return root->val+max(max(left, right),0);//maxPath for root
    }
    
private:
    int global;
};

int main(){
    return 0;
}