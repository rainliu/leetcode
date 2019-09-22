#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution2 {
public:
    bool isPalindrome(ListNode* head) {
        if (head==nullptr) return true;
        
        ListNode dummy = ListNode(0);
        dummy.next = head;
        
        ListNode *p = head;
        int len = 0;
        while (p!=nullptr){
            p=p->next;
            ++len;
        }
      
        int i = 0;
        
        p = &dummy;
        ListNode *q = head;
        while (i<(len+1)/2){
            p=p->next;
            q=q->next;
            ++i;
        }
        p->next=nullptr;  
        
        p = reverse(head);        
        if (len&1) {
            p=p->next;
        }
        
        while (q!=nullptr){
            if (p->val != q->val) {
                return false;
            }
            p = p->next;
            q = q->next;
        }
        
        return true;
    }
    
    ListNode* reverse(ListNode* head) {       
        ListNode *r = nullptr;
        ListNode *p = head;
        while (p!=nullptr){
            ListNode *q = p->next;
            p->next = r;
            r = p;    
            p = q;
        }
        
        return r;
    }
};

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
