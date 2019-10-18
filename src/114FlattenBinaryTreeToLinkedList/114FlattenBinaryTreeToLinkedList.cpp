/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        flatten_helper(root);
    }
    
    pair<TreeNode*, TreeNode*> flatten_helper(TreeNode* root){
        if(root==nullptr) return {nullptr, nullptr};
        auto [left_head, left_tail] = flatten_helper(root->left);
        auto [right_head, right_tail] = flatten_helper(root->right);
        root->left = nullptr;
        if(left_head!=nullptr){
            root->right = left_head;
            left_tail->right = right_head;
            if(right_tail==nullptr){
                right_tail=left_tail;
            }
        }else{
            root->right = right_head;
            if(right_tail==nullptr){
                right_tail = root;
            }
        }
        return {root, right_tail};
    }
};

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
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
click to show hints.
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
    void flatten(TreeNode *root) {
        if(root==nullptr) return;

		flattenTree(root->right);
		TreeNode* last = flattenTree(root->left);				
		if(last!=nullptr){
			last->right = root->right;
			root->right = root->left;
			root->left  = nullptr;
		}
	}

	TreeNode *flattenTree(TreeNode *root){
		if(root==nullptr) return nullptr;
		
		TreeNode* lastRight = flattenTree(root->right);
		TreeNode* lastLeft  = flattenTree(root->left);				
		if(lastLeft!=nullptr){
			lastLeft->right = root->right;
			root->right = root->left;
			root->left  = nullptr;
		}

		if(lastLeft==nullptr&&lastRight==nullptr){
			return root;
		}else if(lastRight==nullptr){
			return lastLeft;
		}else{
			return lastRight;
		}
	}
};

int main(){
	return 0;
}
