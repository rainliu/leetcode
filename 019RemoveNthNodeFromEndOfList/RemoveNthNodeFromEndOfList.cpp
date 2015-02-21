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
https://oj.leetcode.com/problems/remove-nth-node-from-end-of-list/

Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
    	if(n<=0) return head;

    	stack<ListNode*> s;
    	ListNode *p=head;
    	while(p!=nullptr){
    		s.push(p);
    		p=p->next;
    	}    
    	if(n>s.size()) return nullptr;

    	ListNode *q=nullptr;
    	p=s.top(); s.pop();
    	while(!s.empty()&& n){
    		q = p;
    		p = s.top(); s.pop();
    		--n;
    	}
    	if(n){
    		return q;
    	}else{
    		p->next = q->next;
    		return head;
    	}
    }
};

int main(){
	return 0;
}