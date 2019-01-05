impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        nums.sort();
        nums[nums.len()/2]
    }
}

impl BitSolution {
    pub fn majority_element(nums: Vec<i32>) -> i32 {
        let mut counts = vec![0;32];
        for num in &nums{
            for i in 0..32{
                counts[i] += (num>>i) & 1;
            }    
        }
        let mut result = 0;
        let half_n = nums.len() as i32/2;
        for i in 0..32{
            let bit = if counts[i] > half_n {1} else {0};
            result |= bit << i; 
        }
        result
    }
}
