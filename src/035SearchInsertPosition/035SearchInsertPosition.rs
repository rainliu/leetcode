impl Solution {
    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        let n = nums.len() as i32;
        let mut lo = 0;
        let mut hi = n-1;
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
        lo
    }
}
