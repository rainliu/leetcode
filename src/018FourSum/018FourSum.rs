impl Solution {
    pub fn four_sum(nums: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        let mut nums = nums;
        let mut result = vec![];
        let mut i = 0;
        
        nums.sort();
        
        while i < nums.len() as i32 - 3 {
            let mut j = i+1;
            while j < nums.len() as i32 - 2 {
                let (mut k, mut l) = (j+1, nums.len() as i32 - 1);
                while k < l {
                    let sum = nums[i as usize] + nums[j as usize] + nums[k as usize] + nums[l as usize];
                    if sum == target {
                        result.push(vec![nums[i as usize], nums[j as usize], nums[k as usize], nums[l as usize]]);
                        k += 1;
                        while k < l && nums[k as usize] == nums[k as usize-1] {
                            k +=1;
                        }
                    }else if sum < target {
                        k += 1;
                    }else{
                        l -= 1;
                    }
                }
                j += 1;
                while j < nums.len() as i32 - 2 && nums[j as usize] == nums[j as usize-1] {
                    j += 1;
                }
            }
            
            i += 1;
            while i < nums.len() as i32 - 3 && nums[i as usize] == nums[i as usize-1] {
                i += 1;
            }
        }
        return result;
    }
}
