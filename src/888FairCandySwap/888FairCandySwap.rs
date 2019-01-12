use std::iter::FromIterator;
use std::collections::HashSet;
impl Solution {
    pub fn fair_candy_swap(a: Vec<i32>, b: Vec<i32>) -> Vec<i32> {
        let sa:i32 = a.iter().sum();
        let sb:i32 = b.iter().sum();
        let avg = (sa+sb)/2;
        let mut set:HashSet<i32> = HashSet::from_iter(b);
        for i in a {
            let j = avg - (sa - i);
            if set.contains(&j) {
                return vec![i, j]; 
            }
        }
        vec![]
    }
}
