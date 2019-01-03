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
    pub fn is_balanced(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        if let Some(node) = root {
            let mut p = node.borrow_mut();
            let mut left = p.left.take();
            let mut right = p.right.take();
            let left_depth = Self::max_depth(left.as_ref());
            let right_depth = Self::max_depth(right.as_ref());
            return (left_depth-right_depth).abs() <=1 && Self::is_balanced(left) && Self::is_balanced(right);
        }else{
            return true;
        }
    }
    
    fn max_depth(root: Option<&Rc<RefCell<TreeNode>>>) -> i32 {
        match root {
            Some(node) => 1 + std::cmp::max(Self::max_depth(node.borrow().left.as_ref()), Self::max_depth(node.borrow().right.as_ref())),
            None => 0,
        }    
    }
}
