// sliding_window_length - number_of_one > 1
impl Solution {
    pub fn find_max_consecutive_ones(nums: Vec<i32>) -> i32 {
        let (mut i, mut j, mut k) = (0, 0, 0);
        let mut global = 0;
        while j < nums.len() {
            k += nums[j];
            if (j-i+1) as i32 - k > 1 {
                k -= nums[i];
                i += 1;
            }else{
                global = std::cmp::max(global, j-i+1);
            }
            j += 1;
        }
        
        global as i32
    }
}
