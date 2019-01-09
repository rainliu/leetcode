impl Solution {
    pub fn find_max_consecutive_ones(nums: Vec<i32>) -> i32 {
        let mut local = 0;
        let mut global = 0;
        for num in nums {
            local = if num == 0 {0} else {local+num};
            global = std::cmp::max(global, local);
        }
        global
    }
}
