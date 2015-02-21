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
https://oj.leetcode.com/problems/reorder-list/

Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
    	int size = 0;
    	ListNode *p=head;
    	while(p!=nullptr){
    		p=p->next;
    		size++;
    	}
    	if(size<=2) return;
    	
    	int mid = size/2;
        int i = 0;
        ListNode *m = head;
        p = nullptr;
        while(m!=nullptr&&i<mid){
        	p = m;
        	m = m->next;
        	i++;
        }
        ListNode *q = m;
        ListNode *r = q->next;
        while(r!=nullptr){
        	p = q;
        	q = r;
        	r = r->next;
        	q->next = p;
        }
        m->next = nullptr;
        p = head;
        ListNode *pn = p->next;
        ListNode *qn = q->next;

        while(p!=m&&q!=m){
		    p->next = q;
		    q->next = pn;
		    p = pn;
		    q = qn;
		    pn= pn->next;
		    qn= qn->next;
		}
    }
};

int main(){
	return 0;
}