impl Solution {
    pub fn find_max_average(nums: Vec<i32>, k: i32) -> f64 {
        let n = nums.len();
        let mut local = 0;
        for i in 0..(k as usize) {
            local += nums[i];
        }
        let mut global = local;
        for i in (k as usize)..n {
            local += nums[i]-nums[i-(k as usize)];
            global = std::cmp::max(global, local);
        } 
        (global as f64)/(k as f64)
    }
}
