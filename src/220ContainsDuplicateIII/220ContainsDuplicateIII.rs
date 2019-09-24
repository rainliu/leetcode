use std::collections::BTreeMap;
impl Solution {
    pub fn contains_nearby_almost_duplicate(nums: Vec<i32>, k: i32, t: i32) -> bool {
        let mut map = BTreeMap::new();
        for i in 0..nums.len(){  
            /*print!("{}:", i);
            for key in map.keys() {
                print!("{} ", key);
            }
            print!("\n");*/
            if let Some(s) = Solution::binary_search(&map, nums[i], true) {
                //print!("ceiling:{}\n", s);
                if (s as i64 - nums[i] as i64) <= t as i64 {
                    return true;
                }
            }
            if let Some(s) = Solution::binary_search(&map, nums[i], false) {
                //print!("floor:{}\n", s);
                if (nums[i] as i64 - s as i64) <= t as i64 {
                    return true;
                }
            }
                        
            *map.entry(nums[i]).or_insert(0) += 1;
            
            if map.len() > k as usize {
                let mut remove = false;
                if let Some(x) = map.get_mut(&nums[i-k as usize]) {
                    *x -= 1;
                    if *x == 0 {
                        remove = true;
                    }
                }
                if remove {
                    map.remove(&nums[i-k as usize]);
                }
            }
        }
        
        return false;
    }
    
    fn binary_search(map: &BTreeMap<i32,i32>, key: i32, ceiling: bool) -> Option<i32> {
        let keys:Vec<i32> = map.keys().cloned().collect();
        let (mut lo, mut hi) = (0 as i32, keys.len() as i32 - 1);
        while lo <= hi {
            let mi = (lo + (hi-lo)/2) as usize;
            if keys[mi] == key {
                return Some(key);
            }else if keys[mi] < key {
                lo = mi as i32 + 1;
            }else{
                hi = mi as i32 - 1;
            }
        }
        
        if ceiling && lo < keys.len() as i32 && keys[lo as usize] > key {
            return Some(keys[lo as usize]);
        }else if !ceiling && hi >= 0 && keys[hi as usize] < key {
            return Some(keys[hi as usize]);
        }
        
        None
    }
}
