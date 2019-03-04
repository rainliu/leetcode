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
    pub fn diameter_of_binary_tree(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        Self::diameter_of_binary_tree_helper(&root)
    }
    
    pub fn diameter_of_binary_tree_helper(root: &Option<Rc<RefCell<TreeNode>>>) -> i32 {
        if let Some(tn) = root {
            let mut node = tn.borrow();
            let left_depth = Self::max_depth(&node.left);
            let right_depth = Self::max_depth(&node.right);
            let depth = left_depth + right_depth;
            std::cmp::max(std::cmp::max(depth, Self::diameter_of_binary_tree_helper(&node.left)), Self::diameter_of_binary_tree_helper(&node.right))
        }else{
            0
        }
    }
    
    pub fn max_depth(root: &Option<Rc<RefCell<TreeNode>>>) -> i32 {
        if let Some(tn) = root {
            let mut node = tn.borrow();
            1 + std::cmp::max(Self::max_depth(&node.left), Self::max_depth(&node.right))  
        }else{
            0
        }
    }
}
