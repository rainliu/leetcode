use std::collections::HashMap;
impl Solution {
    pub fn find_lhs(nums: Vec<i32>) -> i32 {
        let mut map = HashMap::new();
        for num in nums {
            if let Some(x) = map.get_mut(&num) {
                *x += 1;
            }else{
                map.insert(num, 1);
            }
        }
        let mut global = 0;
        for (key, val) in map.iter() {
            let num = *key+1;
            if let Some(x) = map.get(&num){
                global = std::cmp::max(global, *val+*x);
            }
        }
        global
    }
}
