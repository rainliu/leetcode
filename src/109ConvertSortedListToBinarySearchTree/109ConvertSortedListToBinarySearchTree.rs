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
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn sorted_list_to_bst(head: Option<Box<ListNode>>) -> Option<Rc<RefCell<TreeNode>>> {
        let mut n = 0;
        let mut p = head.as_ref();
        while let Some(node) = p {
            p = node.next.as_ref();
            n+=1;
        }
        Solution::sorted_list_to_bst_helper(&head, n)
    }
    
    fn sorted_list_to_bst_helper(head: &Option<Box<ListNode>>, n: usize) ->Option<Rc<RefCell<TreeNode>>> {
        if n == 0 {
            return None;
        }
        let mut p = head.as_ref();
        let mut i = 0;
        while i < (n-1)/2 {
            p = p.unwrap().next.as_ref();
            i+=1;
        }
        
        let node = p.unwrap();
        let mut root = TreeNode::new(node.val);
        root.left  = Solution::sorted_list_to_bst_helper(head, (n-1)/2);
        root.right = Solution::sorted_list_to_bst_helper(&node.next, n-1-(n-1)/2);
        
        Some(Rc::new(RefCell::new(root)))
    }
}
