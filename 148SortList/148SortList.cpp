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
https://oj.leetcode.com/problems/sort-list/

Sort a linked list in O(n log n) time using constant space complexity.
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *sortList(ListNode *head) {
    	return quickSort(head, nullptr);        
    }

    ListNode *quickSort(ListNode *head, ListNode *tail){
    	if(head==tail) return head;
    	if(head->next==tail) return head;

    	ListNode *LT=head;
        ListNode *GT=head;
        ListNode *p =head;
        ListNode *q =p->next;
    	
    	int min = head->val;
    	int max = head->val;

    	while(q!=tail){
    		p=q;
    		q=q->next;

    		if(p->val>=head->val){
    			if(p->val>max) max = p->val;

    			GT = p;
    		}else{
    			if(p->val<min) min = p->val;

    			GT->next = q;
    			p->next = LT;
    			LT = p;
    		}
    	}
    	if(min<head->val) LT=quickSort(LT, head);
    	if(max>head->val) {
    		GT=quickSort(head->next, tail);
    		head->next = GT;
    	}
    	return LT;
    }
};

int main(){
	return 0;
}