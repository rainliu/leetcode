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
https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

Given a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
    	ListNode *o=nullptr;
    	ListNode *p=head;
    	
    	while(p!=nullptr){
    		ListNode *q=p->next;
    		int r = 0;
	    	while(q!=nullptr&&p->val==q->val){
	    		q=q->next;
	    		r++;
	    	}
	    	if(r){
		    	if(o==nullptr){
		    		head=q;
		    	}else{
		    		o->next=q;
		    	}
		    }else{
		    	o=p;
		    }
		    p=q;
	    }

	    return head;
    }
};

int main(){
	return 0;
}