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
    pub fn is_valid_bst(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        if let Some(node) = root {
            let left = Solution::is_valid_bst_most(node.borrow().left.as_ref(), false);
            let right = Solution::is_valid_bst_most(node.borrow().right.as_ref(), true);
            let cur = node.borrow().val;
            if let Some(left) = left{
                if cur <= left {                    
                    return false;
                }
            }
            if let Some(right) = right{
                if cur >= right {
                    return false;
                }
            }
            
            let mut cur_node = node.borrow_mut();
            let left_node = cur_node.left.take();
            let right_node = cur_node.right.take();
            Solution::is_valid_bst(left_node) && Solution::is_valid_bst(right_node)
        }else{        
            true
        }
    }
    
    fn is_valid_bst_most(root: Option<&Rc<RefCell<TreeNode>>>, left: bool) -> Option<i32> {
        let mut result = None;
        if let Some(node) = root {            
            result = if left {
                Solution::is_valid_bst_most(node.borrow().left.as_ref(), left)
            }else{
                Solution::is_valid_bst_most(node.borrow().right.as_ref(), left)
            };
            if result.is_none() {
                result = Some(node.borrow().val);
            }
        }        
        result
    }
    
    pub fn is_valid_bst_in_order(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        let mut stack = vec![];
        let mut root = root;
        let mut pre = None;
        while root.is_some() || stack.len() > 0 {
            if let Some(node) = root {
                root = node.borrow_mut().left.take();
                stack.push(node);
            }else{
                let node = stack.pop().unwrap();
                let cur = node.borrow().val;
                if let Some(pre) = pre {
                    if cur <= pre {
                        return false;
                    }
                }
                pre = Some(cur);
                root = node.borrow_mut().right.take();
            }
        }
        
        return true;
    }
}
