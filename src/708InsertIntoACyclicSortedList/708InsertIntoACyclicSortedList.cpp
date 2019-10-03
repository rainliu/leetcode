/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (head == nullptr) {
            head = new Node(insertVal, nullptr);
            head->next = head;
            return head;
        }
        
        Node dummy(0, head);
        Node* p = head;
        while (p->next != head) {
            Node* q = p->next;
            if ((insertVal == p->val) || 
                (insertVal > p->val && insertVal < q->val) ||
                ((insertVal > p->val || insertVal < q->val) && q->val < p->val)
               ){
                break;
            }
            p = p->next;
        }
        Node* q = new Node(insertVal, p->next);
        p->next = q;
        
        return dummy.next;
    }
};
