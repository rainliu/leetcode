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
    pub fn convert_bst(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        Self::convert_bst_helper(&root, 0);
        root
    }
    
    pub fn convert_bst_helper(root: &Option<Rc<RefCell<TreeNode>>>, sum: i32) -> i32 {
        let mut sum = sum;
        if let Some(tn) = root {
            let mut n = tn.borrow_mut();
            n.val += Self::convert_bst_helper(&n.right, sum);
            sum = Self::convert_bst_helper(&n.left, n.val);
        }
        sum
    }
}
