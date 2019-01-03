// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Debug)]
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
impl Solution {
    pub fn delete_duplicates(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut dummy = ListNode{val:0, next:head};
        let mut p = dummy.next.as_mut();
        while let Some(q) = p {
            while let Some(r) = q.next.as_mut() {
                if r.val != q.val {
                    break;
                }
                q.next = r.next.take();
            }
            p = q.next.as_mut();
        }
        
        dummy.next
    }
}
