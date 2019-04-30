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
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut dummy = ListNode::new(0);
        let mut l = &mut dummy;
        let mut l1 = l1;
        let mut l2 = l2;
        let mut c = 0;
        while let (Some(p1), Some(p2)) = (l1.as_mut(), l2.as_mut()) {
            let d = p1.val + p2.val + c;
            c = d/10;
            l.next = Some(Box::new(ListNode::new(d%10)));
            l = l.next.as_mut().unwrap();
            l1 = p1.next.take();
            l2 = p2.next.take();
        }
        let mut l3 = if l1.is_some() {
            l1
        }else{
            l2
        };
        while let Some(p3) = l3.as_mut() {
            let d = p3.val + c;
            c = d/10;
            l.next = Some(Box::new(ListNode::new(d%10)));
            l = l.next.as_mut().unwrap();
            l3 = p3.next.take();
        }
        if c != 0 {
            l.next = Some(Box::new(ListNode::new(c)));
        }
        
        return dummy.next;
    }
}

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
impl Solution2 {
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut dummy = ListNode::new(0);
        let mut l = &mut dummy;
        let mut l1 = l1;
        let mut l2 = l2;
        let mut c = 0;
        while l1.is_some() || l2.is_some() {
            let v1 = if let Some(p1) = l1.as_mut() {
                let v = p1.val;
                l1 = p1.next.take();
                v
            }else{
                0
            };
            let v2 = if let Some(p2) = l2.as_mut() {
                let v = p2.val;
                l2 = p2.next.take();
                v
            }else{
                0
            };
            let d = v1 + v2 + c;
            c = d/10;
            l.next = Some(Box::new(ListNode::new(d%10)));
            l = l.next.as_mut().unwrap();
        }
        if c != 0 {
            l.next = Some(Box::new(ListNode::new(c)));
        }
        
        return dummy.next;
    }
}
