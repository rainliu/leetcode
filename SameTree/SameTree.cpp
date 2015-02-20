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
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
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
    bool isSameTree(TreeNode *p, TreeNode *q) {
      if(p==nullptr&&q==nullptr) return true;
      if((p==nullptr&&q!=nullptr)||(p!=nullptr&&q==nullptr)) return false;
      return p->val==q->val && isSameTree(p->left, q->left)&&isSameTree(p->right, q->right);
    }
};


int main(){
	return 0;
}