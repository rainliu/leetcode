impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        let n = nums.len();
        if n == 0 {return 0;}
        let mut i:i32 = -1;
        let mut j:usize = 0;
        while j < n {
            while j < n && nums[j] == val {
                j += 1;
            }
            if j < n {
                i += 1;
                nums.swap(i as usize, j);
                j += 1;
            }
        }
        i+1
    }
}
