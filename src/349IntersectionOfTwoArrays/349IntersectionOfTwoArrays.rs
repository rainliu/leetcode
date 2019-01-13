use std::collections::HashSet;
use std::iter::FromIterator;
impl Solution {
    pub fn intersection(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut set:HashSet<i32> = HashSet::from_iter(nums2);
        let mut result = vec![];
        for num in nums1{
            if set.contains(&num){
                result.push(num);
                set.remove(&num);
            }    
        }
        result
    }
}
