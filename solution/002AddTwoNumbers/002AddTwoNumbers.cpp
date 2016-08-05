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
https://oj.leetcode.com/problems/add-two-numbers/

You are given two linked lists representing two non-negative numbers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    	int m = 0;
    	int n = 0;

    	ListNode *p1=l1;
    	while(p1!=nullptr) { m++; p1=p1->next; }    
    	ListNode *p2=l2;
    	while(p2!=nullptr) { n++; p2=p2->next; }

    	ListNode *r, *p0, *pp=nullptr;
    	if(m>=n) r = l1;
    	else 	 r = l2; 

    	int c = 0;
    	p0=r; p1=l1; p2=l2; 
    	while(p1!=nullptr&&p2!=nullptr){
    		c += p1->val+p2->val;
    		p0->val = c%10;
    		c /= 10;

    		pp=p0;
    		p0=p0->next;
    		p1=p1->next;
    		p2=p2->next;
    	}

    	while(p0!=nullptr){
    		c += p0->val;
    		p0->val = c%10;
    		c /= 10;

    		pp=p0;
    		p0=p0->next;
    	}

    	if(c>0){
    		pp->next = new ListNode(c);
    	}

    	return r;
    }
};

int main(){
	return 0;
}