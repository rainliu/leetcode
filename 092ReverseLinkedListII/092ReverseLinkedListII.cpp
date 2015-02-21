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
https://oj.leetcode.com/problems/reverse-linked-list-ii/

Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
    	if(m==n) return head;

        ListNode *o=nullptr;
        ListNode *p=head;
        ListNode *q=head;
        ListNode *r=q->next;
        int i=1;
        while(q->next!=nullptr&&i<m){
        	p=q;
        	o=p;
        	q=q->next;
        	r=q->next;
        	i++;
        }
        while(i<n){
        	p=q;
        	q=r;
        	r=r->next;
        	q->next=p;	
        	i++;
        }
        if(o==nullptr){
        	head->next = r;
        	return q;
        }else{
        	if(o->next!=nullptr) o->next->next = r;
        	o->next = q;
        	return head;
        }
    }
};

int main(){
	return 0;
}