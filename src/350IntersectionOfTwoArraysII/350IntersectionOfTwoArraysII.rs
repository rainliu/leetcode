use std::collections::HashMap;
impl Solution {
    pub fn intersect(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut map = HashMap::new();
        for num in nums2{
            if let Some(x) = map.get_mut(&num) {
                *x += 1;
            }else{
                map.insert(num, 1);
            }
        }
        let mut result = vec![];
        for num in nums1{
            if let Some(x) = map.get_mut(&num) {
                result.push(num);
                *x -= 1;
                if *x == 0 {
                    map.remove(&num);
                }
            }
        }
        result
    }
}
