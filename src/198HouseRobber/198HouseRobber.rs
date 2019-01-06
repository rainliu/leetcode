impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        let mut fns = vec![0;4];
        let mut global = 0;
        for i in 0..nums.len() {
            fns[0] = nums[i] + std::cmp::max(fns[3], fns[2]);
            global = std::cmp::max(global, fns[0]);
            fns[3] = fns[2];
            fns[2] = fns[1];
            fns[1] = fns[0];
        }
        global
    }
}
