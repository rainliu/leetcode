#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
 		ListNode *even, *odd;
    	ListNode dummy(0);
    	ListNode *cur = &dummy;

    	dummy.next = head;
        while(cur->next!=NULL && cur->next->next!=NULL){
        	even = cur->next;
        	odd  = cur->next->next;

        	cur->next = odd;
        	even->next = odd->next;
        	odd->next = even;
        	cur = even;
        }

        return dummy.next;
    }
};


int main(){
	Solution s;

	return 0;
} 