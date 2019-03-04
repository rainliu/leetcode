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
    pub fn is_subtree(s: Option<Rc<RefCell<TreeNode>>>, t: Option<Rc<RefCell<TreeNode>>>) -> bool {
        Self::is_subtree_helper(&s, &t)
    }
    
    pub fn is_subtree_helper(s: &Option<Rc<RefCell<TreeNode>>>, t: &Option<Rc<RefCell<TreeNode>>>) -> bool {
        if Self::is_sametree(&s, &t) {
            true
        } else if let Some(stn) = &s {
            let sn = stn.borrow();
            Self::is_subtree_helper(&sn.left, &t) || Self::is_subtree_helper(&sn.right, &t)
        } else {
            false
        }  
    }
    
    pub fn is_sametree(s: &Option<Rc<RefCell<TreeNode>>>, t: &Option<Rc<RefCell<TreeNode>>>) -> bool {
        match (s, t) {
            (Some(stn), Some(ttn)) => {
                let sn = stn.borrow();
                let tn = ttn.borrow();
                sn.val == tn.val && Self::is_sametree(&sn.left, &tn.left) && Self::is_sametree(&sn.right, &tn.right)
            }
            (None, None) => true,
            _ => false,
        }
    }
}
