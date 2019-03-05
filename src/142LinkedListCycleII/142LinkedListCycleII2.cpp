
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
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr){
            return nullptr;
        }
        ListNode *p1 = head;
        ListNode *p2 = head;
        while(p2!=nullptr){
            if(p2->next!=nullptr && p2->next->next!=nullptr){
                p2 = p2->next->next;
            }else{
                return nullptr;
            }
            if(p1->next!=nullptr){
                p1 = p1->next;
            }
            if(p1==p2){
                break;
            }
        }
        p1 = head;
        while(p1!=p2){
            p1=p1->next;
            p2=p2->next;
        }
        return p1;
    }
};

int main(){
    return 0;
}