#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int K = lists.size();       
        if(K==0) return NULL;

        for(int step = 1; (1<<(step-1))<K; ++step){
            for(int k=0; k<K; k+=(1<<step)){
                if(k+(1<<(step-1)) < K){
                    lists[k] = mergeTwoLists(lists[k], lists[k+(1<<(step-1))]);
                }
            }
        }
       

        return lists[0];
    }

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