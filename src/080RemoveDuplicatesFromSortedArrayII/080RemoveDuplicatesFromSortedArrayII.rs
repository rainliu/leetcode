impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let (mut i, mut j, mut k, n) = (0, 0, 0, nums.len());
        const d: usize = 2;
        while j < n {
            if nums[j] != nums[i-k] {
                nums.swap(i, j);
                k = 1;
                i += 1;
            } else if nums[j] == nums[i-k] && k < d {
                nums.swap(i,j);
                k+=1;
                i+=1;
            }
            
            j += 1;
        }
        
        i as i32
    }
}
