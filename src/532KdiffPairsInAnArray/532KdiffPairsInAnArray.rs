impl Solution {
    pub fn find_pairs(nums: Vec<i32>, k: i32) -> i32 {
        if k < 0  {return 0;}
        let mut map = std::collections::HashMap::new();
        let mut count = 0;
        for num in nums {
            if k == 0 {
                if let Some(x) = map.get_mut(&num) {
                    if *x == 1 {
                        count += 1;
                    }
                    *x += 1;
                }else{
                    map.insert(num, 1);
                }
            }else if !map.contains_key(&num) {
                let i = num+k;
                let j = num-k;
                if map.contains_key(&i) {
                    count += 1;
                }
                if map.contains_key(&j) {
                    count += 1;
                }
                map.insert(num, 1);
            }
        }
        count
    }
}
