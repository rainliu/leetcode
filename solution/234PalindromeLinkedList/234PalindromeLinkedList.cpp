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
  bool isPalindrome(ListNode *head) {
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
};

int main() { return 0; }