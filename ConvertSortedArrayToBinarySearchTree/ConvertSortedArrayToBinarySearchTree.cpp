#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/

//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
  		if(num.size()==0) return NULL;
        return toBST(num, 0, num.size()-1);
    }

    TreeNode *toBST(vector<int> &num, int low, int hig){
    	TreeNode *root = NULL;
    	if(low<=hig){
        	int mid = low + (hig-low)/2;
        	root = new TreeNode(num[mid]);
        	root->left =toBST(num, low, mid-1);
        	root->right=toBST(num, mid+1, hig);
        }

        return root;
    }
};



int main(){
	Solution s;

	return 0;
} 