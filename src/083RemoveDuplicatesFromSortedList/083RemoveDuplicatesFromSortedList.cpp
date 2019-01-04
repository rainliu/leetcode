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
https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list/

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *i=head, *j=head;
        while(j!=nullptr){
        	while(j!=nullptr&&j->val==i->val){
        		j=j->next;
        	}
        	ListNode *k=i->next;
        	while(k!=nullptr&&k!=j){
        		ListNode *d = k;
        		k=k->next;
        		delete d;
        	}
        	i->next = j;
        	i=j;
        }
        return head;
    }
};

int main(){
	return 0;
}