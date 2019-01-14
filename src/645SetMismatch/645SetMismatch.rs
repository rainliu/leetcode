impl Solution {
    pub fn find_error_nums(nums: Vec<i32>) -> Vec<i32> {
        let mut nums:Vec<i32> = nums.into_iter().map(|x| x-1).collect();
        let mut i = 0;
        while i < nums.len() {
            if nums[i] as usize != i {
                let j = nums[i] as usize;
                if nums[j] as usize != j {
                    nums.swap(i, j);
                    continue;
                }
            }
            i+=1;
        }
        for i in 0..nums.len() {
            if nums[i] as usize != i {
                return vec![nums[i]+1, i as i32+1];
            }
        }
        vec![]
    }
}
