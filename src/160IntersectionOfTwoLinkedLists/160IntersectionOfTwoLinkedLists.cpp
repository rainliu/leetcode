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
https://oj.leetcode.com/problems/intersection-of-two-linked-lists/

Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    	int m=0, n=0, d;
    	
    	ListNode *p=headA;
    	while(p!=nullptr){
    		m++;
    		p=p->next;
    	}        
    	
    	ListNode *q=headB;
    	while(q!=nullptr){
    		n++;
    		q=q->next;
    	}     

    	if(m>n){
    		d = m-n;
    		p=headA; q=headB;
	    	while(p!=nullptr&&d){
	    		d--;
	    		p=p->next;
	    	}        
    	}else{
    		d = n-m;
    		p=headA; q=headB;
	    	while(q!=nullptr&&d){
	    		d--;
	    		q=q->next;
	    	}
    	}

    	ListNode *r=(p==q?p:nullptr);
    	while(p!=nullptr&q!=nullptr&&p!=q){
    		p=p->next; q=q->next;
			if(p==q){
				r=p;
				break;
			}
	    }

	    return r;
    }
};

class Solution2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    	stack<ListNode*> sA, sB;
    	
    	ListNode *p=headA;
    	while(p!=nullptr){
    		sA.push(p);
    		p=p->next;
    	}        
    	
    	ListNode *q=headB;
    	while(q!=nullptr){
    		sB.push(q);
    		q=q->next;
    	}     

    	ListNode *r=nullptr;
    	while(!sA.empty()&&!sB.empty()){
	    	p=sA.top(); sA.pop();   
			q=sB.top(); sB.pop();
			if(p==q) r=p;
			else break;
	    }

	    return r;
    }
};

int main(){
	return 0;
}