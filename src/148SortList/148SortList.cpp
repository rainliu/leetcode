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


class SolutionMerge {
public:
    ListNode* sortList(ListNode* head) {
        if (head==nullptr || head->next==nullptr) return head;
        ListNode* prev = head;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast!=nullptr && fast->next!=nullptr){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        
        ListNode*l1 = sortList(head);
        ListNode*l2 = sortList(slow);
        return mergeList(l1, l2);
    }
    
    ListNode* mergeList(ListNode* l1, ListNode* l2) {
        ListNode dummy = ListNode(0);
        ListNode *p = &dummy;
        while (l1!=nullptr && l2!=nullptr){
            if(l1->val < l2->val){
                p->next = l1;
                l1 = l1->next;
            }else{
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if (l1!=nullptr){
            p->next = l1;
        }else{
            p->next = l2;
        }     
        
        return dummy.next;
    }
    
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
    	if(max>head->val) head->next=quickSort(head->next, tail);
    	
    	return LT;
    }
};

int main(){
	return 0;
}
