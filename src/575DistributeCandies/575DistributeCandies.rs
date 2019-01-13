use std::collections::HashSet;
use std::iter::FromIterator;
impl Solution {
    pub fn distribute_candies(candies: Vec<i32>) -> i32 {
        let n = candies.len();
        let set:HashSet<i32> = HashSet::from_iter(candies);
        return std::cmp::min(n/2, set.len()) as i32;
    }
}
