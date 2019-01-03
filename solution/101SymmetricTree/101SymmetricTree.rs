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
    pub fn is_symmetric(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        Self::is_symmetric_helper(root.clone(), root)
    }
    fn is_symmetric_helper(p: Option<Rc<RefCell<TreeNode>>>, q: Option<Rc<RefCell<TreeNode>>>) -> bool {
        match (p, q) {
            (Some(p), Some(q)) => {
                let mut pn = p.borrow();
                let mut qn = q.borrow();
                pn.val == qn.val &&
                Self::is_symmetric_helper(pn.left.clone(), qn.right.clone()) &&
                Self::is_symmetric_helper(pn.right.clone(), qn.left.clone())
            }
            (None, None) => true,
            _=> false,
        }    
    }
}
