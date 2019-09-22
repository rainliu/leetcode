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
impl Solution {
    pub fn rotate_right(head: Option<Box<ListNode>>, k: i32) -> Option<Box<ListNode>> {
        let mut dummy = Some(Box::new(ListNode{val: 0, next: head}));
        
        let mut p = dummy.as_ref().unwrap().next.as_ref();
        let mut len = 0;
        while let Some(l) = p {
            p = l.next.as_ref();
            len += 1;
        }
        
        if k <= 0 || len == 0{
            return dummy.unwrap().next;
        }
        
        
        let mut k = k % len;
        if k > 0 {
            let mut n = len-k;
            let mut r = dummy.as_mut();
            while n > 0 {
                r = r.unwrap().next.as_mut();
                n -= 1;
            }
            let mut p = r.unwrap().next.take();
            r.unwrap().next = None;
            
            let mut q = dummy.as_mut().unwrap().next.take();
            dummy.as_mut().unwrap().next = p;
            
            let mut p = dummy.as_mut();
            while k > 0 {
                p = p.unwrap().next.as_mut();
                k -= 1;
            }
            p.unwrap().next = q;
        }
        
        
        return dummy.unwrap().next;
    }
}
