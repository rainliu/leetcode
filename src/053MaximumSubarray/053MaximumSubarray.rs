impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let mut local = nums[0];
        let mut global = nums[0];
        for i in 1..nums.len() {
            local = std::cmp::max(nums[i],local+nums[i]); 
            global = std::cmp::max(global,local);  
        }
        global
    }
}
