#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(head==NULL) return NULL;
        vector<int> num;

        while(head!=NULL){
            num.push_back(head->val);
            head=head->next;
        }

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