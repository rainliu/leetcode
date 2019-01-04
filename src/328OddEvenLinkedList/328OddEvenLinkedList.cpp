#include <iostream>
using namespace std;

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
  ListNode *oddEvenList(ListNode *head) {
    ListNode *oddHead = head;
    ListNode *evenHead = head != nullptr ? head->next : nullptr;
    ListNode *p = oddHead;
    ListNode *q = evenHead;
    while (q != nullptr && q->next != nullptr) {
      ListNode *r = q->next;
      ListNode *o = r->next;
      q->next = o;
      r->next = evenHead;
      p->next = r;
      p = p->next;
      q = q->next;
    }
    return oddHead;
  }
};

int main() { return 0; }