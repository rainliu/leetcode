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
    ListNode* plusOne(ListNode* head) {
        head = reverse(head);       
        
        ListNode dummy = ListNode(0);
        dummy.next = head;
        int c = 1;
        ListNode* p = &dummy;
        while(head!=nullptr){
            head->val += c;
            c = head->val/10;
            head->val %= 10;
            p = head;
            head=head->next;
        }
        if(c>0){
            p->next = new ListNode(c);
        }
        head = dummy.next;
        
        return reverse(head);
    }
    
    ListNode* reverse(ListNode* head) {
        ListNode* r = nullptr;
        ListNode* p = head;
        while(p!=nullptr){
            ListNode* q = p->next;
            p->next = r;
            r = p;
            p = q;
        }
        return r;
    }
};
