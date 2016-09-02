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
https://oj.leetcode.com/problems/rotate-list/

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given  1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
    	if(head==nullptr) return nullptr;

    	int size = 1;
    	ListNode *tail=head;
    	while(tail->next!=nullptr){
    		tail=tail->next;
    		size++;
    	}
    	k %= size;
    	if(k==0) return head;

    	tail->next = head;

    	ListNode *p=head;
    	ListNode *q=head;
    	int i=0;
    	while(i<k){
    		q=q->next;
    		i++;
    	}
    	while(q!=tail){
    		p=p->next;
    		q=q->next;
    	}
    	q=p->next;
    	p->next = nullptr;
    	return q;
    }
};

int main(){
	return 0;
}