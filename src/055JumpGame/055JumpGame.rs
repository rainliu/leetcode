impl Solution {
    pub fn can_jump(nums: Vec<i32>) -> bool {
        if nums.len() == 0 {
            return false;
        }
        let mut pos = 0;
        while nums[pos] != 0 && (pos + nums[pos] as usize) < nums.len()-1 {
            let mut max_val = 0;
            let mut next = pos;
            for i in 1..=(nums[pos] as usize) {
                if (pos+i+nums[pos+i] as usize) >= max_val {
                    next = pos+i;
                    max_val = pos+i+nums[pos+i] as usize;
                }
            }
            pos = next;
        }
        return (pos + nums[pos] as usize) >= nums.len()-1;
    }
}
