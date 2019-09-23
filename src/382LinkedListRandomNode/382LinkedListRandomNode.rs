use rand::{thread_rng, Rng};

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
struct Solution {
    head: Option<Box<ListNode>>
}

//https://en.wikipedia.org/wiki/Reservoir_sampling
/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Solution {

    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    fn new(head: Option<Box<ListNode>>) -> Self {
        Solution {
            head,
        }
    }
    
    /** Returns a random node's value. */
    fn get_random(&self) -> i32 {
        let mut p = self.head.as_ref();
        let mut i:u32 = 0;
        let mut result = 0;
        let mut rng = thread_rng();
        while let Some(l) = p {
            let j: u32 = rng.gen_range(0, i+1);
            if j == i {
                result = l.val;
            }
            p = l.next.as_ref();
            
            i+=1;
        }
        
        result
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * let obj = Solution::new(head);
 * let ret_1: i32 = obj.get_random();
 */
