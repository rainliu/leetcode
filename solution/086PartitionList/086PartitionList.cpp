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
https://oj.leetcode.com/problems/partition-list/

Given a linked list and a value x, partition it such that all nodes 
less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given  1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if(head==nullptr) return nullptr;

    	ListNode dummy(x);
    	dummy.next = head;

        ListNode *p = &dummy;
        ListNode *q = head;
        ListNode *r = q->next; 

        while(r!=nullptr&&q->val<x){
        	p=q;
        	q=r;
    		r=r->next;
        }
        if(r==nullptr){
            return head;
        }
        ListNode *n = p;
        ListNode *o = q;
        while(r!=nullptr){
        	if(o->val<x){
        		n->next=r;
        		o->next=q;
        		p->next=o;
        		p = p->next;
        	}else{
        		n = o;
        	}
			o = r;
        	r = r->next;
        }
        if(o->val<x){
    		n->next=r;
    		o->next=q;
    		p->next=o;
    		p = p->next;
    	}

        return dummy.next;
    }
};

int main(){
	return 0;
}