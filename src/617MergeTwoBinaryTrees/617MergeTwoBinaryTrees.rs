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
    pub fn merge_trees(t1: Option<Rc<RefCell<TreeNode>>>, t2: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        match (t1, t2) {
            (Some(tn1), Some(tn2)) => {
                {
                    let mut n1 = tn1.borrow_mut();
                    let mut n2 = tn2.borrow_mut();
                    n1.val += n2.val;
                    n1.left = Self::merge_trees(n1.left.take(), n2.left.take());
                    n1.right = Self::merge_trees(n1.right.take(), n2.right.take());
                }
                Some(tn1)
            }
            (Some(tn1), None) => Some(tn1),
            (None, Some(tn2)) => Some(tn2),
            _ => None,
        }
    }
}
