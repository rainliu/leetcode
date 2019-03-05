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

use std::collections::BinaryHeap;
use std::cmp::Reverse;
use std::cmp::Ordering;

impl Ord for ListNode {
    fn cmp(&self, other: &ListNode) -> Ordering {
        self.val.cmp(&other.val)
    }
}

impl PartialOrd for ListNode {
    fn partial_cmp(&self, other: &ListNode) -> Option<Ordering> {
        Some(self.val.cmp(&other.val))
    }
}

impl Solution {
    pub fn merge_k_lists(lists: Vec<Option<Box<ListNode>>>) -> Option<Box<ListNode>> {
        let mut min_heap = BinaryHeap::new();
        for list in lists{
            if let Some(ln) = list{
                min_heap.push(Reverse(ln));
            }
        }
        
        let mut dummy = ListNode::new(0);
        let mut p = &mut dummy;
        while !min_heap.is_empty() {
            //https://doc.rust-lang.org/src/core/cmp.rs.html#423
            //pub struct Reverse<T>(pub T);
            //Reverse is tuple-style struct, therefore, 
            //use .0 for access the internal data
            let mut list = min_heap.pop().unwrap().0;
            if let Some(ln) = list.next.take(){
                min_heap.push(Reverse(ln));
            } 
            p.next = Some(list);
            p = p.next.as_mut().unwrap();
        }
        
        dummy.next
    }
}
