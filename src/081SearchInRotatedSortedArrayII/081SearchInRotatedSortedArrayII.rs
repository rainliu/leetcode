impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> bool {
        let (mut lo, mut hi) = (0 as i32, nums.len() as i32 - 1);
        while (lo<hi && nums[lo as usize]==nums[hi as usize]) {hi-=1;}
        while (lo<=hi) {
            let mi = lo + (hi-lo)/2;
            if nums[mi as usize] == target {
                return true;
            }else if nums[mi as usize] >= nums[lo as usize] {
                if target < nums[mi as usize] && target >= nums[lo as usize] {
                    hi = mi - 1;
                }else{
                    lo = mi + 1;
                }
            }else{
                if target > nums[mi as usize] && target <= nums[hi as usize] {
                    lo = mi + 1;
                }else{
                    hi = mi - 1;
                }
            }
            while (lo<hi && nums[lo as usize]==nums[hi as usize]) {hi-=1;}
        }
        return false;
    }
}
