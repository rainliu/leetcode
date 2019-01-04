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
    pub fn has_path_sum(root: Option<Rc<RefCell<TreeNode>>>, sum: i32) -> bool {
        match root {
            Some(node) => {
                let mut p = node.borrow_mut();
                let sum = sum - p.val;
                if p.left.is_none() && p.right.is_none() {
                    sum == 0
                }else{
                    Self::has_path_sum(p.left.take(), sum) || 
                    Self::has_path_sum(p.right.take(), sum)
                }
            }
            None => false,
        }    
    }
}
