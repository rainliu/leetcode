impl Solution {
    pub fn sort_transformed_array(nums: Vec<i32>, a: i32, b: i32, c: i32) -> Vec<i32> {
        if nums.len() == 0 {
            return vec![];
        }
        let mut nums = nums;
        for i in 0..nums.len(){
            nums[i] = Solution::transform(nums[i], a, b, c);
        }
        let mut sorted = vec![0; nums.len()];
        let mut k = if a>=0 {nums.len() - 1} else {0};
        let (mut i, mut j) = (0, nums.len() - 1);
        while i <= j {
            if a >= 0 {
                sorted[k] = if nums[i] >= nums[j] { i += 1; nums[i-1] } else { j -= 1; nums[j+1]};                
                k -= 1;
            }else{
                sorted[k] = if nums[i] <= nums[j] { i += 1; nums[i-1] } else { j -= 1; nums[j+1]};             
                k += 1;
            }
        }        
        
        sorted
    }
    
    fn transform(x: i32, a:i32, b:i32, c:i32) -> i32{
        a*x*x + b*x + c
    }
}
