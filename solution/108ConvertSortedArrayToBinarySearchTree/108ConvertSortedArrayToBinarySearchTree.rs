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
    pub fn sorted_array_to_bst(nums: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        Self::sorted_array_to_bst_helper(&nums, 0, nums.len() as i32 - 1)
    }
    
    fn sorted_array_to_bst_helper(nums: &Vec<i32>, lo: i32, hi: i32) -> Option<Rc<RefCell<TreeNode>>> {
        if lo > hi {
            return None;
        }
        
        let mi = lo + (hi-lo)/2;
        let mut root = TreeNode::new(nums[mi as usize]);
        root.left = Self::sorted_array_to_bst_helper(nums, lo, mi-1);
        root.right = Self::sorted_array_to_bst_helper(nums, mi+1, hi);
        
        Some(Rc::new(RefCell::new(root)))
    }
}
