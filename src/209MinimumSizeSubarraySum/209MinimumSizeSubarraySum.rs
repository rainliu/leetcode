impl Solution {
    pub fn min_sub_array_len(s: i32, nums: Vec<i32>) -> i32 {
        let (mut i, mut j, mut k) = (0, 0, nums.len()+1);
        
        let mut sum = 0;
        while j < nums.len() {      
            sum += nums[j];
            while sum >= s {
                k = std::cmp::min(k, j-i+1);
                sum -= nums[i];
                i += 1;
            }
            j+=1;
        }
        if k==nums.len()+1{
            0
        }else{
            k as i32
        }
    }
}
