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
    pub fn get_minimum_difference(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut stack = vec![];
        if let Some(root) = root {
            stack.push(root); 
        }
        
        let mut pre = None;
        let mut global = std::i32::MAX;
        while !stack.is_empty() {
            let mut root = stack.pop().unwrap();    
            let mut l = root.borrow_mut().left.take();
            if let Some(left) = l  {
                stack.push(root);
                stack.push(left);
            }else{
                {
                    if let Some(p) = pre {
                        global = std::cmp::min(root.borrow().val-p, global);
                    }
                    pre = Some(root.borrow().val);
                }
                
                let mut r = root.borrow_mut().right.take();
                if let Some(right) = r {
                    stack.push(right);
                }
            }
        }
        global
    }
}
