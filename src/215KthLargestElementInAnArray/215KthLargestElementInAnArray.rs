impl Solution {
    pub fn find_kth_largest(nums: Vec<i32>, k: i32) -> i32 {
        let mut nums = nums;
        let (mut lo, mut hi) = (0 as i32, nums.len() as i32 - 1);
        return Solution::find_kth_largest_helper(&mut nums, (hi+1-k) as usize, lo, hi);
    }
    
    fn find_kth_largest_helper(nums:&mut [i32], k: usize, mut lo: i32, mut hi: i32) -> i32 {
        let (mut pilot, mut i, mut j) = (lo, lo+1, hi);
        while i <= j {
            if nums[i as usize] <= nums[pilot as usize] {
                i += 1;
            }else{
                nums.swap(i as usize, j as usize);
                j -= 1;
            }
        }
        nums.swap(pilot as usize, j as usize);
        pilot = j;
        
        if pilot as usize == k {
            return nums[k];
        }else if (pilot as usize) < k{
            return Solution::find_kth_largest_helper(nums, k, pilot+1, hi);
        }else{
            return Solution::find_kth_largest_helper(nums, k, lo, pilot-1);
        }
    }
}
