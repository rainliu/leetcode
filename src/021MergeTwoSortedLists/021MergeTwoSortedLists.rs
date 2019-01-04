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
    pub fn merge_two_lists(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut dummy = ListNode::new(0);
        let mut l = &mut dummy;
        let (mut l1, mut l2) = (l1, l2);
        while l1.is_some() && l2.is_some() {
            let (v1, v2) = (l1.as_ref().map(|n| n.val).unwrap(), l2.as_ref().map(|n| n.val).unwrap());
            let v = if v1 < v2 {
                l1 = l1.map(|n| n.next).unwrap();
                v1
            } else {
                l2 = l2.map(|n| n.next).unwrap();
                v2
            };
            l.next = Some(Box::new(ListNode::new(v)));
            l = l.next.as_mut().unwrap();
        }
        
        if l1.is_some() {
            l.next = l1;
        }else{
            l.next = l2;
        }

        dummy.next
    }
}
