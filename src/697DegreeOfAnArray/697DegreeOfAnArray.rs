impl Solution {
    pub fn find_shortest_sub_array(nums: Vec<i32>) -> i32 {
        let mut map = std::collections::HashMap::new();
        let mut pos = std::collections::HashMap::new();
        for i in 0..nums.len() {
            if let Some(x) = map.get_mut(&nums[i]) {
                *x += 1;
            }else{
                map.insert(nums[i], 1);
            }
            if let Some((b, e)) = pos.get_mut(&nums[i]) {
                *e = i;
            }else{
                pos.insert(nums[i], (i,i));
            }
        }
        let mut global = std::i32::MAX;
        if let Some(max_val) = map.values().max(){
            for (key, val) in map.iter() {
                if *val == *max_val {
                    if let Some((b, e)) = pos.get(key) {
                        global = std::cmp::min(global, (*e-*b + 1) as i32); 
                    }
                }
            }
        }
        
        global
    }
}
