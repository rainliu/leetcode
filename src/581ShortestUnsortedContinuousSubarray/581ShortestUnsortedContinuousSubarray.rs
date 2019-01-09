impl SlowSolution {
    pub fn find_unsorted_subarray(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        let n = nums.len();
        let mut s = n;
        let mut e = 1;
        for i in 1..n {
            if nums[i]<nums[i-1] {
                e = i;
                let mut j = i;
                while j>=1 && nums[j-1]>nums[j] {
                    nums.swap(j-1, j);
                    j -= 1;
                }
                s = std::cmp::min(s, j);
            }
        }
        if s >= e {
            0
        }else{
            (e-s+1) as i32
        }
    }
}


impl Solution {
    pub fn find_unsorted_subarray(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        let n = nums.len();
        let mut s = -1;
        let mut e = -2;
        let mut max = nums[0];
        let mut min = nums[n-1];
        for i in 1..n {
            max = std::cmp::max(max, nums[i]);
            min = std::cmp::min(min, nums[n-1-i]);
            if nums[i] < max {e=i as i32;}
            if nums[n-1-i]>min {s=(n-1-i) as i32;}
        }
        (e-s+1) as i32
    }
}
