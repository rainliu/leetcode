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
  ListNode *removeElements(ListNode *head, int val) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode *r = &dummy;
    ListNode *p = head;
    while (p != nullptr) {
      if (p->val == val) {
        r->next = p->next;
      } else {
        r = p;
      }
      p = p->next;
    }
    return dummy.next;
  }
};

int main() {}