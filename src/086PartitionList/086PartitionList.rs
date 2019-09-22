// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
//
// r
// 1->4->3->2->5->2
// p->1->2->2
//         /
//       /
//     /
// q->4->3->5

impl Solution {
    pub fn partition(head: Option<Box<ListNode>>, x: i32) -> Option<Box<ListNode>> {
        let mut dummy1 = Some(Box::new(ListNode::new(0)));
        let mut dummy2 = Some(Box::new(ListNode::new(0)));
        let mut p = dummy1.as_mut();
        let mut q = dummy2.as_mut();
        
        let mut head = head;
        while let Some(mut r) = head {
            head = r.next.take();
            if r.val < x {
                p.as_mut().unwrap().next = Some(r);
                p = p.unwrap().next.as_mut();
            }else{
                q.as_mut().unwrap().next = Some(r);
                q = q.unwrap().next.as_mut();
            }
        }
        
        p.as_mut().unwrap().next = dummy2.unwrap().next.take();
            
        dummy1.unwrap().next        
    }
}

/*
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy1 = ListNode(0);
        ListNode dummy2 = ListNode(0);
        ListNode *p = &dummy1;
        ListNode *q = &dummy2;
        
        ListNode *r = head;
        while (r!=nullptr) {
            if (r->val < x) {
               p->next = r;               
               p = p->next;
            }else{
               q->next = r; 
               q = q->next;
            }
            r = r->next;
        }
        
        if (p!=nullptr){
            p->next = dummy2.next;    
            q->next = nullptr;
        }
        
        return dummy1.next;
    }
};*/
