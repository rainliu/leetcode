impl Solution {
    pub fn product_except_self(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len(); 
        assert!(n>1);
        
        let mut left  = vec![1; n];
        let mut right = vec![1; n];
        for i in 1..n {
            left[i] = left[i-1]*nums[i-1];
            right[n-1-i] = right[n-i]*nums[n-i];
        }
        let mut result = vec![0; n];
        for i in 0..n {
            result[i] = left[i]*right[i];
        }
        return result;
    }
}
