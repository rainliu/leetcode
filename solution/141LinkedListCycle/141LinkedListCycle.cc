#include <iostream>

/**
 * Definition for singly-linked list.
 */
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *p1 = head;
        ListNode *p2 = head;
        while(p2!=nullptr){
            if(p2->next!=nullptr && p2->next->next!=nullptr){
                p2 = p2->next->next;
            }else{
                return false;
            }
            if(p1->next!=nullptr){
                p1 = p1->next;
            }
            if(p1==p2){
                return true;
            }
        }
        return false;
    }
};

int main(){
    return 0;
}