impl Solution {
    pub fn missing_number(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        let mut p = 0;
        let n = nums.len() as i32;
        while p < n {
            if nums[p as usize] >= n ||
               nums[p as usize] == p {
                p += 1;
            }else{
                let q = nums[p as usize];
                nums.swap(p as usize, q as usize);
            }
        }
        for p in 0..n {
            if nums[p as usize] != p { return p; }
        }
        n
    }
}

impl Solution2 {
    pub fn missing_number(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        let mut p = 0;
        let mut n = nums.len();
        while p < n {
            if nums[p] == p as i32 {
                p += 1;
            }else if nums[p] == n as i32 {
                nums.swap(p, n-1);
                n -= 1;
            }else{
                let q = nums[p];
                nums.swap(p, q as usize);
            }
        }
        p as i32
    }
}
