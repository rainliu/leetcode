#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/


 //Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
 
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> nodeMap;
   		
   		RandomListNode *backup = head;
   		RandomListNode dummy(0);
   		RandomListNode *curr = &dummy;

   		while(head!=NULL){
   			curr->next = new RandomListNode(head->label); 
   			nodeMap[head] = curr->next;
   			head = head->next;
   			curr = curr->next;
   		}
   		curr->next = NULL;
   		head = backup;
   		curr = dummy.next;
   		while(head!=NULL){
   			if(head->random!=NULL){
   				curr->random = nodeMap[head->random];
   			}
   			head = head->next;
   			curr = curr->next;
   		}

   		return dummy.next;
    }
};


int main(){
	Solution s;

	return 0;
} 