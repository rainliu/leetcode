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
impl Solution1 {
    pub fn inorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut result = vec![];
        let mut stack = vec![];
        let mut root = root;
        while root.is_some() || stack.len() > 0 {
            if let Some(node) = root {
                root = node.borrow_mut().left.take();
                stack.push(node);
            }else{
                let node = stack.pop().unwrap();
                result.push(node.borrow().val);
                root = node.borrow_mut().right.take();
            }
        }
        
        result
    }
}

impl Solution2 {
    pub fn inorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut values = vec![];
        Solution::inorder_traversal_helper(&root, &mut values);
        values
    }
    fn inorder_traversal_helper(root: &Option<Rc<RefCell<TreeNode>>>, values: &mut Vec<i32>)  {
        if let Some(node) = root {
            Solution::inorder_traversal_helper(&node.borrow().left, values);
            values.push(node.borrow().val);
            Solution::inorder_traversal_helper(&node.borrow().right, values);
        }
    }
}
