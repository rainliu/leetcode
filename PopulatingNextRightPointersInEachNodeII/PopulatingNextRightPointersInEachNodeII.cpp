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
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
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
        if(root==nullptr) return;  
        root->next = nullptr;
        connect2(root);
    }

    void connect2(TreeLinkNode *root) {
        if(root==nullptr) return;  

        if(root->left!=nullptr) {
            root->left->next = root->right;
        }

        if(root->right!=nullptr) {
            root->right->next = root->next==nullptr?nullptr:(root->next->left==nullptr?root->next->right:root->next->left);
        }

        connect2(root->left);
        connect2(root->right);
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