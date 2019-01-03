impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let n = nums.len();
        if n == 0 { return 0; }
        let mut i:usize = 0;
        let mut j:usize = 1;
        while j < n {
           while j < n && nums[j] == nums[i] {
               j += 1;
            } 
            if j < n {
                i += 1;
                nums.swap(i, j);
                j += 1;
            }
        }
        (i+1) as i32
    }
}
