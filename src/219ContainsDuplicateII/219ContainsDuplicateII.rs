impl Solution {
    pub fn contains_nearby_duplicate(nums: Vec<i32>, k: i32) -> bool {
        let mut map = std::collections::HashMap::<i32, i32>::new();
        for i in 0..(nums.len() as i32) {
            if let Some(j) = map.get(&nums[i as usize]){
                if (*j-i).abs() <= k {
                    return true;
                }
            }
            map.insert(nums[i as usize], i);
        }
        false
    }
}
