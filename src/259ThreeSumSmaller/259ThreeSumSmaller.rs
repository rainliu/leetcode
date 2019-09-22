impl Solution {
    pub fn three_sum_smaller(nums: Vec<i32>, target: i32) -> i32 {
        let mut nums = nums;
        nums.sort();
        
        let (mut i, mut count) = (0, 0);
        while i < (nums.len() as i32 - 2) {
            let target2 = target-nums[i as usize];
            let (mut j, mut k) = (i + 1, nums.len() as i32 - 1);
            while k > j {
                if nums[j as usize] + nums[k as usize] < target2 {
                    count += k - j;
                    j += 1;
                }else{
                    k -= 1;
                }
            }
            i += 1;
        }
        
        count
    }
}
