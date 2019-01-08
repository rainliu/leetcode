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
    pub fn middle_node(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut slow = &head;
        let mut fast = &head;
        while fast.is_some() && fast.as_ref().unwrap().next.is_some() {
            slow = &slow.as_ref().unwrap().next;
            fast = &fast.as_ref().unwrap().next.as_ref().unwrap().next;
        }
        Self::clone_list_from_ref(slow)
    }
    
    fn clone_list_from_ref(head: &Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        if head.is_none() {return None;}
        let mut dummy = ListNode::new(0);
        let mut p = &mut dummy;
        let mut q = head;
        while let Some(node) = q.as_ref() {
            p.next = Some(Box::new(ListNode::new(node.val)));
            q = &node.next;
            p = p.next.as_mut().unwrap();
        }
        dummy.next
    }
}
