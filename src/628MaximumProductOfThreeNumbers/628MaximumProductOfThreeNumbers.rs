impl Solution {
    pub fn maximum_product(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        let n = nums.len();
        nums.sort();
        std::cmp::max(nums[0]*nums[1], nums[n-3]*nums[n-2])*nums[n-1]
    }
}
