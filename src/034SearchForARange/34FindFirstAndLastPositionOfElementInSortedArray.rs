impl Solution {
    pub fn search_range(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut mi = Solution::binary_search(&nums, target, 0, nums.len() as i32 - 1);
        if mi == -1 {
            return vec![-1, -1];
        }
        let (mut lo, mut hi) = (mi, mi);
        
        mi = 0;
        while mi != -1 {
            mi = Solution::binary_search(&nums, target, hi+1, nums.len() as i32 - 1);
            if mi != -1 {
                hi = mi;    
            }
        }
        
        mi = 0;
        while mi != -1 {
            mi = Solution::binary_search(&nums, target, 0, lo - 1);
            if mi != -1 {
                lo = mi;    
            }
        }
        
        vec![lo, hi]
    }
    
    fn binary_search(nums: &[i32], target: i32, mut lo: i32, mut hi: i32) -> i32 {
        while lo <= hi {
            let mi = lo + (hi-lo)/2;
            if nums[mi as usize] == target {
                return mi;
            }else if nums[mi as usize] < target {
                lo = mi + 1;
            }else{
                hi = mi - 1;
            }
        }
        
        return -1;
    }
}
