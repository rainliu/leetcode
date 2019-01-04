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
    pub fn level_order_bottom(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        let mut queue = std::collections::VecDeque::new();
        let mut last_level:i32 = -1;
        if let Some(node) = root {
            queue.push_back((node, 0));
        }
        let mut results = vec![];
        while let Some((node, level)) = queue.pop_front() {
            if last_level != level as i32 {
                results.push(vec![]);
                last_level = level as i32;
            }
            let mut n = node.borrow_mut();
            results[level].push(n.val);
            if n.left.is_some() {
                queue.push_back((Rc::clone(n.left.as_mut().unwrap()), level+1));
            }
            if n.right.is_some() {
                queue.push_back((Rc::clone(n.right.as_mut().unwrap()), level+1));
            }
        }
        results.into_iter().rev().collect()
    }
}
