use rand::{thread_rng, Rng};

struct Solution {
    nums: Vec<i32>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Solution {

    fn new(nums: Vec<i32>) -> Self {
        Solution {
            nums,
        }
    }
    
    fn pick(&self, target: i32) -> i32 {
        let mut rng = thread_rng();
        let mut i: usize = 0;
        let mut index = 0;
        for k in 0..self.nums.len(){
            if self.nums[k] == target {
                let j: usize = rng.gen_range(0, i+1);
                if j == i {
                    index = k;
                }
                i += 1;
            }
        }
        
        index as i32
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * let obj = Solution::new(nums);
 * let ret_1: i32 = obj.pick(target);
 */
