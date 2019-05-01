impl Solution {
    pub fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut nums = nums;
        nums.sort();
        let mut results = vec![];
        let mut i = 0 as i32;
        while i < nums.len() as i32 - 2{
            let t = -nums[i as usize];
            let (mut j, mut k) = (i as i32 + 1, nums.len() as i32 - 1);
            while j < k {
                let (l, r) = (nums[j as usize], nums[k as usize]);
                if l + r == t {
                    results.push(vec![-t, l, r]);
                }
                if l + r <= t {
                    while j+1 < k && nums[j as usize + 1] == nums[j as usize]{
                        j += 1;
                    }
                    j += 1;
                }else{
                    while j < k-1 && nums[k as usize - 1] == nums[k as usize]{
                        k -= 1;
                    }
                    k -= 1;
                }
            }
            while i+1 < nums.len() as i32 - 2 && nums[i as usize + 1] == nums[i as usize] {
                i += 1;    
            }
            i += 1;
        }
        results
    }
}
