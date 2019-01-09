impl Solution {
    pub fn find_disappeared_numbers(nums: Vec<i32>) -> Vec<i32> {
        let mut nums: Vec<i32> = nums.into_iter().map(|x| x-1).collect();
        let n = nums.len();
        let mut p = 0 as usize;
        while p < n {
            if nums[p] != p as i32 {
                let q = nums[p] as usize;
                if nums[q] != q as i32 {
                    nums.swap(p, q);
                    continue;
                }
            }    
            p += 1;
        }
        
        let mut result = vec![];
        for p in 0..n {
            if nums[p] != p as i32 {
                result.push( (p+1) as i32);
            }
        }
        
        result
    }
}
