impl Solution {
    pub fn circular_array_loop(nums: Vec<i32>) -> bool {
        for start in 0..nums.len() {
            if Solution::is_loop(&nums, start, nums.len()) {
                return true;
            }
        }
        
        false
    }
    
    fn is_loop(nums:&[i32], start: usize, len: usize) -> bool {
        let (mut slow, mut slow_addr) = (nums[start], start as i32);
        let (mut fast, mut fast_addr) = (nums[start], start as i32);
        let len1000 = (len*1000) as i32;
        if Solution::is_positive(fast) != Solution::is_positive(nums[((fast_addr+fast+len1000)%len as i32) as usize]) {
            //print!("{}:1\n", start);
            return false;
        }
        let (fast2, fast_addr2) = (nums[((fast_addr+fast+len1000)%len as i32) as usize], (fast_addr+fast+len1000)%len as i32);
        fast = fast2;
        fast_addr = fast_addr2;
        //print!("fast_addr:{}\n", fast_addr);
        while slow_addr != fast_addr {
            if Solution::is_positive(fast) != Solution::is_positive(nums[((fast_addr+fast+len1000)%len as i32) as usize]) {
                print!("{}:2\n", start);
                return false;
            }
            let (fast2, fast_addr2) = (nums[((fast_addr+fast+len1000)%len as i32) as usize], (fast_addr+fast+len1000)%len as i32);
            fast = fast2;
            fast_addr = fast_addr2;
            //print!("fast_addr:{}\n", fast_addr);
            
            if Solution::is_positive(fast) != Solution::is_positive(nums[((fast_addr+fast+len1000)%len as i32) as usize]) {
                //print!("3:{}:{}\n", start, fast_addr);
                return false;
            }
            let (fast2, fast_addr2) = (nums[((fast_addr+fast+len1000)%len as i32) as usize], (fast_addr+fast+len1000)%len as i32);
            fast = fast2;
            fast_addr = fast_addr2;
            //print!("fast_addr:{}\n", fast_addr);
            
            let (slow2, slow_addr2) = (nums[((slow_addr+slow+len1000)%len as i32) as usize], (slow_addr+slow+len1000)%len as i32);
            slow = slow2;
            slow_addr = slow_addr2;
        }
        
        
        slow_addr != (slow_addr+slow+len1000)%len as i32
    }
    
    fn is_positive(num: i32) -> bool {
        num > 0
    }
}
