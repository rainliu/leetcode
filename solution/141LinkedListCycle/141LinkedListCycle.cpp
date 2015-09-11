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
https://oj.leetcode.com/problems/linked-list-cycle/

Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
    	if(head==nullptr) return false;
    	
    	ListNode *p = nullptr;
    	ListNode *q = head;
    	ListNode *r = q->next;

    	while(r!=nullptr&&r!=head){
    		q->next = p;
    		p = q;
    		q = r;
    		r = r->next;
    	}

    	return r==head;
    }
};

class Solution2 {
public:
    bool hasCycle(ListNode *head) {
        if(head==nullptr) return false;

        ListNode *first=head;
        ListNode *second=head;

        do{
            first = first->next;
            if(second->next==nullptr) return false;
            else second = second->next->next;
        }while(first!=nullptr&&second!=nullptr&&first!=second);
        
        return first==second;
    }
};

class Solution3 {
public:
    bool hasCycle(ListNode *head) {
    	if(head==nullptr) return false;

    	unordered_map<ListNode *, bool> m;

    	do{
    		if(m.find(head)!=m.end()){
    			return true;
    		}else{
    			m[head] = false;
    		}

    		head=head->next;
    	}while(head!=nullptr);

    	return false;
    }
};

int main(){
	return 0;
}