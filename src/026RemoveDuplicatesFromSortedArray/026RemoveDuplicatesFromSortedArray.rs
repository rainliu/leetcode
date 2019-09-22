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

impl Solution2 {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let (mut i, mut j, mut k, n) = (0, 0, 0, nums.len());
        const d: usize = 1;
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
