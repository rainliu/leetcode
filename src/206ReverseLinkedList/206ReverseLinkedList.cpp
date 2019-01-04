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
  ListNode *reverseList(ListNode *head) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode *r = &dummy;
    ListNode *p = head;
    while (p != nullptr) {
      ListNode *q = p->next;
      p->next = r;
      r = p;
      p = q;
    }

    if (dummy.next != nullptr) {
      dummy.next->next = nullptr;
      return r;
    } else {
      return nullptr;
    }
  }
};
int main() {}