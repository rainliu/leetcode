#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;

        ListNode *head, *cur;
        if(l1->val<l2->val){
        	cur = head = l1;
        	l1=l1->next;
        }else{
        	cur = head = l2;
        	l2=l2->next;
        }

        while(l1!=NULL&&l2!=NULL){
        	if(l1->val<l2->val){
	        	cur->next = l1; 
	        	l1=l1->next;
	        }else{
	        	cur->next = l2;
	        	l2=l2->next;
	        }
	        cur = cur->next;
        }

        while(l1!=NULL){
        	cur->next = l1; 
	        l1=l1->next;
	        cur = cur->next;
        }
       	while(l2!=NULL){
       		cur->next = l2;
	        l2=l2->next;
	        cur = cur->next;
       	}
       	cur->next=NULL;

        return head;
    }
};



int main(){
	Solution s;

	return 0;
} 