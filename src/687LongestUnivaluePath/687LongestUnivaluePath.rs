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
    pub fn longest_univalue_path(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        if let Some(root) = root {
            let mut global = 0;
            let mut node = root.borrow_mut();
            let l = Self::longest_univalue_path_helper(node.left.take(), node.val, &mut global);
            let r = Self::longest_univalue_path_helper(node.right.take(), node.val, &mut global);
            std::cmp::max(global, l+r)
        }else{
            0
        }
    }
    
    fn longest_univalue_path_helper(root: Option<Rc<RefCell<TreeNode>>>, val: i32, global: &mut i32) -> i32 {
        if let Some(root) = root {
            let mut node = root.borrow_mut();
            let l = Self::longest_univalue_path_helper(node.left.take(), if node.val == val {val} else {node.val}, global);
            let r = Self::longest_univalue_path_helper(node.right.take(), if node.val == val {val} else {node.val}, global);
            if node.val == val {
                1+std::cmp::max(l, r)
            }else{
                *global = std::cmp::max(*global, l+r);
                0
            }
        }else{
            0    
        }
    }
}
