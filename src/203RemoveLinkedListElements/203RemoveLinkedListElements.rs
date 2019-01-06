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
    pub fn remove_elements(head: Option<Box<ListNode>>, val: i32) -> Option<Box<ListNode>> {
        let mut dummy = ListNode{val:0, next:head};
        let mut p = &mut dummy;
        while let Some(q) = p.next.as_mut() {
            if q.val == val {
                p.next = q.next.take();
            }else{
                p = p.next.as_mut().unwrap();
            }
        }
        
        dummy.next
    }
}
