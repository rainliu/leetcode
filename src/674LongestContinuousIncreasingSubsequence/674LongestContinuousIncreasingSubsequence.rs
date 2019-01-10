impl Solution {
    pub fn find_length_of_lcis(nums: Vec<i32>) -> i32 {
        if nums.len()==0 {return 0;}
        let mut global = 0;
        let mut local = 0;
        for i in 1..nums.len() {
            local = if nums[i]>nums[i-1] {local+1} else {0};
            global = std::cmp::max(global, local);
        }
        global+1
    }
}
