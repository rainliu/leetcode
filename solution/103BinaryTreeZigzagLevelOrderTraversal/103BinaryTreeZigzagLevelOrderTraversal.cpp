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
Given a binary tree, return the zigzag level order traversal of its nodes' values. 
(ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    	vector<vector<int>> result;
    	if(root==nullptr) return result;

    	vector<int> zig;
    	int level = 0, last_level=-1;
    	queue<TreeNode *> q;
    	queue<int> p;
    	q.push(root); p.push(level);
    	while(!q.empty()){
    		root = q.front(); q.pop();
    		level= p.front(); p.pop();

    		if(level!=last_level){
    			if(last_level!=-1){
    				if(last_level&0x1){
    					reverse(zig.begin(), zig.end());
    				}
    				result.push_back(zig);
    			}
    			zig.clear();
    		}
    		last_level = level;
    		zig.push_back(root->val);
    		if(root->left!=nullptr)  {q.push(root->left);  p.push(level+1);}
    		if(root->right!=nullptr) {q.push(root->right); p.push(level+1);}
    	}
    	if(level&0x1){
			reverse(zig.begin(), zig.end());
		}
		result.push_back(zig);

    	return result;
    }
};

int main(){
	Solution s;

	return 0;
}