impl Solution {
    pub fn sort_colors(nums: &mut Vec<i32>) {
        let (mut i, mut j) = (0 as i32, nums.len() as i32 - 1);
        let mut k = 0;
        while k <= j {
            if nums[k as usize] < 1 {
                nums.swap(k as usize, i as usize);
                i += 1;
                k += 1;
            }else if nums[k as usize] > 1 {
                nums.swap(k as usize, j as usize);
                j -= 1;
            }else{
                k += 1;
            }
        }
    }
}
