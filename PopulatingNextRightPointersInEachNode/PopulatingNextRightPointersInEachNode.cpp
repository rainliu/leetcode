#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

/*
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. 
If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree 
(ie, all leaves are at the same level, and every parent has two children).

For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/

// Definition for binary tree with next pointer.
struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
    }
};

class Solution2 {
public:
    void connect(TreeLinkNode *root) {
     	if(root==nullptr) return;   

		queue<TreeLinkNode *> q;
     	queue<int> p;

     	int level = 0, last_level = -1;
     	TreeLinkNode *last_node=nullptr;
     	
     	q.push(root); p.push(level);
     	while(!q.empty()){
     		root = q.front(); q.pop();
     		level= p.front(); p.pop();
     		
     		if(last_node!=nullptr){
	     		last_node->next = level!=last_level ? nullptr : root;
		    }
     		last_level = level;
     		last_node  = root;
     		if(root->left!=nullptr)  {q.push(root->left);  p.push(level+1);}
     		if(root->right!=nullptr) {q.push(root->right); p.push(level+1);}
     	}     	
	    root->next = nullptr;
    }
};

int main(){
	return 0;
}