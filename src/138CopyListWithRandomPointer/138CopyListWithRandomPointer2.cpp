#include <unordered_map>

using namespace std;

/**
 * Definition for singly-linked list with a random pointer.
 */
  struct RandomListNode {
      int label;
      RandomListNode *next, *random;
      RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
  };

class Solution2 {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> map;
        Node dummy = Node(0, nullptr, nullptr);
        Node* p = &dummy;
        Node* q = head;
        while (q != nullptr) {
            p->next = new Node(q->val, nullptr, nullptr);
            p = p->next;
            map.insert({q, p});
            q = q->next;
        }
        q = head;
        p = dummy.next;
        while (q != nullptr) {
            if (q->random != nullptr) {
                p->random = map[q->random];
            }
            q = q->next;
            p = p->next;
        }
        
        return dummy.next;
    }
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head==nullptr){
            return head;
        }
        unordered_map<RandomListNode *, RandomListNode *> m;
        RandomListNode *r=nullptr, *p = head, *q;
        while(p!=nullptr){
            q=new RandomListNode(p->label);
            if(r==nullptr){
                r=q;
            }
            m[p]=q;
            p=p->next;
        }
        p=head;
        q=r;
        while(p!=nullptr){
            if(p->random!=nullptr){
                q->random = m[p->random];
            }
            if(p->next!=nullptr){
                q->next = m[p->next];
            }
            p=p->next;
            q=q->next;
        }

        return r;
    }
};

int main(){
    return 0;
}
