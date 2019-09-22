impl Solution {
    pub fn three_sum_closest(nums: Vec<i32>, target: i32) -> i32 {
        let mut nums = nums;
        nums.sort();
        let mut sum = std::i32::MAX;
        for k in 0..nums.len() as i32 -2 {
            let target2 = target - nums[k as usize];
            let (mut i, mut j) = (k+1 as i32, nums.len() as i32 -1);
            while i < j {
                let sum3 = nums[i as usize] + nums[j as usize] - target2;
                if sum3 == 0 {
                    return target;
                }else if sum3.abs() < sum.abs() {
                    sum = sum3;
                }
                
                if sum3 < 0 {
                    i+=1;
                }else{
                    j-=1;
                }
            }            
        }
        
        return sum+target;
    }
}
