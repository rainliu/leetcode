/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n <= 0) {
            return head;
        }
        
        ListNode dummy = ListNode(0);
        dummy.next = head;
        ListNode *r = &dummy;
        ListNode *p = dummy.next;
        ListNode *q = dummy.next;
                
        while (n-- > 0 && q != nullptr) {
            q = q->next;
        }
        
        while (q!= nullptr) {
            r = r->next;
            p = p->next;
            q = q->next;
        }
        
        r->next = p->next;        
        
        return dummy.next;
    }
};
