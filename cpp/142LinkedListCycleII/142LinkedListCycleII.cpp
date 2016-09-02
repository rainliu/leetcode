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
https://oj.leetcode.com/problems/linked-list-cycle-ii/

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

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
    ListNode *detectCycle(ListNode *head) {
    	if(head==nullptr) return nullptr;

        ListNode *first=head;
        ListNode *second=head;

        do{
            first = first->next;
            if(second->next==nullptr) return nullptr;
            else second = second->next->next;
        }while(first!=nullptr&&second!=nullptr&&first!=second);
        
        if(second==nullptr || first==nullptr) return nullptr;

        first = head;
        while(first!=second){
        	first = first->next;
        	second= second->next;
        }
    
    	return first;
    }
};

class Solution2 {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr) return nullptr;

    	unordered_map<ListNode *, bool> m;

    	do{
    		if(m.find(head)!=m.end()){
    			return head;
    		}else{
    			m[head] = false;
    		}

    		head=head->next;
    	}while(head!=nullptr);

    	return nullptr;
    }
};

int main(){
	return 0;
}