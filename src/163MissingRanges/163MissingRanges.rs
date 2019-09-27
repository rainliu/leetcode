impl Solution {
    pub fn find_missing_ranges(nums: Vec<i32>, lower: i32, upper: i32) -> Vec<String> {
        let mut result = vec![];
        if nums.len() == 0 {
            if upper == lower {
                result.push(format!("{}", lower));     
            } else {
                result.push(format!("{}->{}", lower, upper));
            }
        }else{
            for i in 0..nums.len() {
                if i == 0 {
                    if nums[i] as i64 - lower as i64 == 1 {
                        result.push(format!("{}", lower));     
                    } else if nums[i] as i64 - lower as i64 > 1 {
                        result.push(format!("{}->{}", lower, nums[i] - 1));
                    }
                }else{
                     if nums[i] as i64 - nums[i-1] as i64 == 2 {
                        result.push(format!("{}", nums[i-1]+1));     
                    } else if nums[i] as i64 - nums[i-1] as i64 > 2 {
                        result.push(format!("{}->{}", nums[i-1] + 1, nums[i] - 1));
                    }
                }

                if i==nums.len()-1 {
                    if upper as i64 - nums[i] as i64 == 1 {
                        result.push(format!("{}", upper));     
                    } else if upper as i64 - nums[i] as i64 > 1 {
                        result.push(format!("{}->{}", nums[i] + 1, upper));
                    }
                }
            }        
        }
        
        return result;
    }
}
