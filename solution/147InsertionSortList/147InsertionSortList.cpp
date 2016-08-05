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
https://oj.leetcode.com/problems/insertion-sort-list/

Sort a linked list using insertion sort.
*/

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
   		if(head==nullptr) return nullptr;

   		ListNode *p=head;
   		ListNode *q=head;
   		ListNode *r=q->next;

   		while(r!=nullptr){
   			q=r;
   			r=r->next;

   			if(q->val<p->val){
   				p->next=r;

   				if(q->val<head->val){
   					q->next = head;
   					head = q;	
   				}else{
   					ListNode *o=nullptr;
   					ListNode *n=head;
   					while(n->val<=q->val){
   						o=n;
   						n=n->next;
   					}
   					o->next = q;
   					q->next = n;
   				}
   			}else{
   				p=q;
   			}
   		}     

   		return head;
    }
};

int main(){
	return 0;
}