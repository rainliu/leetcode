#include <iostream>
#include <vector>
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
  bool isPalindrome1(ListNode *head) {
    vector<int> p;
    while (head != nullptr) {
      p.push_back(head->val);
      head = head->next;
    }
    int lo = 0;
    int hi = p.size() - 1;
    while (lo <= hi) {
      if (p[lo] != p[hi]) {
        return false;
      }
      lo++;
      hi--;
    }
    return true;
  }

  bool isPalindrome(ListNode *head) {
    int n = 0;
    ListNode *p = head;
    while (p != nullptr) {
      n++;
      p = p->next;
    }
    if (n <= 1)
      return true;
    int mid = n / 2;
    p = head;
    while (mid != 0) {
      p = p->next;
      mid--;
    }
    // cout<<p->val;
    ListNode *q = p->next;
    while (q != nullptr) {
      ListNode *r = q->next;
      q->next = p;
      p = q;
      q = r;
    }
    q = head;
    mid = n / 2;
    while (mid) {
      mid--;
      // cout << mid << q->val << p->val << endl;
      if (q->val != p->val) {
        return false;
      }
      q = q->next;
      // cout << mid;
      p = p->next;
      // cout << mid << endl;
    }
    return true;
  }
};

int main() {
  Solution s;
  ListNode *p1 = new ListNode(1);
  ListNode *p2 = new ListNode(2);
  ListNode *p3 = new ListNode(2);
  p1->next = p2;
  p2->next = p3;
  cout << "it is" << s.isPalindrome(p1) << endl;
  return 0;
}