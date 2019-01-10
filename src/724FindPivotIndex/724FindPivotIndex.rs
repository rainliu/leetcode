impl Solution {
    pub fn pivot_index(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut left = vec![0;n];
        let mut right= vec![0;n];
        for i in 1..n {
            left[i] = left[i-1]+nums[i-1];
            right[n-1-i] = right[n-i]+nums[n-i];
        }
        for i in 0..n{
            if left[i]==right[i]{
                return i as i32
            }
        }
        -1
    }
}

impl LessSpaceSolution {
    pub fn pivot_index(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let sum:i32 = nums.iter().sum();
        let mut left = 0;
        for i in 0..n {
            if left == sum-left-nums[i] {return i as i32;}
            left += nums[i];
        }
        -1
    }
}
