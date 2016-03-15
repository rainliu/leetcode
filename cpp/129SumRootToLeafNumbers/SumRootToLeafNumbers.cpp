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
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
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
    int sumNumbers(TreeNode *root) {
     	if(root==nullptr) return 0;

     	vector<vector<int>> numbers;
     	edgeTo[root] = nullptr;
     	path(root, numbers);

     	int sum = 0;
     	for(int i=0; i<numbers.size(); ++i){
     		int base = 1;
     		for(int j=0; j<numbers[i].size(); ++j){
     			sum+=numbers[i][j]*base;
     			base*=10;
     		}
     	}

     	return sum;
    }

    void path(TreeNode *root, vector<vector<int>> &numbers){
    	if(root->left==nullptr&&root->right==nullptr){
    		vector<int> v;
          	do{
            	v.push_back(root->val);
            	root=edgeTo[root];
          	}while(root!=nullptr);
          	numbers.push_back(v);
    	}else{
    		if(root->left!=nullptr){
    			edgeTo[root->left]  = root;
    			path(root->left, numbers);
    		}
    		if(root->right!=nullptr){
    			edgeTo[root->right] = root;
    			path(root->right, numbers);
    		}
    	}
    }
private:
	unordered_map<TreeNode*, TreeNode*> edgeTo;
};

int main(){
	return 0;
}