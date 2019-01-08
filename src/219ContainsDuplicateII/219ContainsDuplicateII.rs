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

impl LessSpaceSolution {
    pub fn contains_nearby_duplicate(nums: Vec<i32>, k: i32) -> bool {
        // assert!(k>0);
        let mut set = std::collections::HashSet::new();
        for i in 0..(nums.len() as i32) {
            if i>k {set.remove(&nums[(i-k-1) as usize]);}
            if set.contains(&nums[i as usize]) {return true;}
            set.insert(nums[i as usize]);
        }
        false
    }
}
