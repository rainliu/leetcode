use std::collections::HashSet;
impl Solution {
    pub fn repeated_n_times(a: Vec<i32>) -> i32 {
        let mut set = HashSet::new();
        for num in a {
            if set.contains(&num) {
                return num;
            }else{
                set.insert(num);
            }
        }
        0
    }
}
