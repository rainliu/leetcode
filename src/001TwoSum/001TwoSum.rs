impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut m = std::collections::HashMap::new();
        for i in 0..nums.len() {
            if let Some(j) = m.get(&nums[i]) {
                return vec![*j as i32,i as i32];
            }else{
                m.insert(target-nums[i], i);
            }
        }
        vec![]
    }
}
