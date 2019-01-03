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
    pub fn min_depth(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        match root {
            Some(node) => {
                let mut p = node.borrow_mut();
                if p.left.is_none() && p.right.is_none() {
                    1    
                }else if p.left.is_none(){
                    1 + Self::min_depth(p.right.take())
                }else if p.right.is_none(){
                    1 + Self::min_depth(p.left.take())
                }else{
                    1 + std::cmp::min(Self::min_depth(p.left.take()), Self::min_depth(p.right.take()))
                }
            }
            None => 0,
        }
    }
}
