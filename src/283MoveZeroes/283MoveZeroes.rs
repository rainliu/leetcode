impl Solution {
    pub fn move_zeroes(nums: &mut Vec<i32>) {
        let n = nums.len();
        let mut z = 0;
        let mut p = 0;
        while p < n {
             if nums[p] != 0 {
                nums.swap(z, p);
                z += 1;
            }
            p += 1;
        }
    }
}
