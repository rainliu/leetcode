#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
(ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
    	vector<vector<int>> v;
    	if(root==nullptr) return v;

    	queue<TreeNode *> q;
    	queue<int> p;
    	vector<int> o;
    	int level=0, last_level=-1;

    	q.push(root); p.push(level);
    	while(!q.empty()){
    		root = q.front(); q.pop();
    		level= p.front(); p.pop();
    		if(level!=last_level){
    			if(last_level!=-1){
    				v.insert(v.begin(), o);
    			}
    			o.clear();
    		}
    		o.push_back(root->val);
    		last_level = level;
    		if(root->left!=nullptr)  {q.push(root->left);  p.push(level+1);}
    		if(root->right!=nullptr) {q.push(root->right); p.push(level+1);}
    	}
    	v.insert(v.begin(), o);

    	return v;
    }
};

int main(){
	return 0;
}