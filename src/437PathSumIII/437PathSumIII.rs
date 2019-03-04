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
    pub fn path_sum(root: Option<Rc<RefCell<TreeNode>>>, sum: i32) -> i32 {
        Self::path_sum_helper(&root, sum)
    }
    
    pub fn path_sum_helper(root: &Option<Rc<RefCell<TreeNode>>>, sum: i32) -> i32 {
        let mut count = Self::sum_up(root, sum, 0);
        if let Some(tn) = root{
            let n = tn.borrow();
            count += Self::path_sum_helper(&n.left, sum);
            count += Self::path_sum_helper(&n.right, sum);
        }
        count
    }
    
    pub fn sum_up(root: &Option<Rc<RefCell<TreeNode>>>, sum: i32, val: i32) -> i32 {
        let mut count = 0;
        if let Some(tn) = root {
            let n = tn.borrow();
            count = if sum == val+n.val {1} else {0};
            count += Self::sum_up(&n.left, sum, val+n.val) +
                     Self::sum_up(&n.right, sum, val+n.val); 
        }
        count
    }
}
