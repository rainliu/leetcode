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
    pub fn is_same_tree(p: Option<Rc<RefCell<TreeNode>>>, q: Option<Rc<RefCell<TreeNode>>>) -> bool {
        match (p,q) {
            (Some(pt), Some(qt)) => {
                let mut ptn = pt.borrow_mut();
                let mut qtn = qt.borrow_mut();
                ptn.val == qtn.val && Self::is_same_tree(ptn.left.take(), qtn.left.take()) && Self::is_same_tree(ptn.right.take(), qtn.right.take())
            }
            (None, None) => true,
            _ => false,
        }
    }
}
