impl Solution {
    pub fn check_possibility(nums: Vec<i32>) -> bool {
        let mut nums = nums;
        let n = nums.len();
        let mut cnt = 0;
        let mut i = 1;
        while i < n && cnt <= 1 {
            if nums[i-1]>nums[i]{
                cnt+=1;
                if i>=2 && nums[i-2]>nums[i] {nums[i]=nums[i-1];}
                else {nums[i-1]=nums[i];}
            } 
            i += 1;
        }
        cnt<=1
    }
}
