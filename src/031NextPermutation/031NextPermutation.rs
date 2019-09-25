impl Solution {
    pub fn next_permutation(nums: &mut Vec<i32>) {
        if nums.len() == 0 {
            return;
        }
        let mut i = nums.len() - 1;
        while i>0 {
            if nums[i-1]>=nums[i] {
                i-=1;
            }else{
                break;
            }
        }
        if i > 0 {
            let mut j = nums.len() - 1;
            while j >= i {
                if nums[j] <= nums[i-1] {
                    j-=1;
                }else{
                    nums.swap(i-1, j);
                    break;
                }
            }
        }
        nums[i..].reverse();
    }
}
