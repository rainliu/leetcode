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
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
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
    bool isSymmetric(TreeNode *root) {
    	if(root==nullptr) return true;
    	return isSymmetricTree(root->left, root->right);
    }  

    bool isSymmetricTree(TreeNode *p, TreeNode *q) {
      	if(p==nullptr&&q==nullptr) return true;
      	if((p==nullptr&&q!=nullptr)||(p!=nullptr&&q==nullptr)) return false;
      	return p->val==q->val && isSymmetricTree(p->left, q->right)&&isSymmetricTree(p->right, q->left);
    }
};


int main(){
	return 0;
}