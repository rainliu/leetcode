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
    pub fn invert_tree(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        Self::invert_tree_helper(&root);
        root
    }
    
    pub fn invert_tree_helper(root: &Option<Rc<RefCell<TreeNode>>>) -> &Option<Rc<RefCell<TreeNode>>> {
        if let Some(tn) = root {
            let mut node = tn.borrow_mut();
            let l = node.left.take();
            let r = node.right.take();
            if let Some(x) = l {
                node.right.replace(x);
            }
            if let Some(x) = r {
                node.left.replace(x);
            }
            Self::invert_tree_helper(&node.left);
            Self::invert_tree_helper(&node.right);
        }
        
        root
    }
}
