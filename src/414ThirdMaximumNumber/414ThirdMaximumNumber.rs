impl Solution {
    pub fn third_max(nums: Vec<i32>) -> i32 {
        let mut max1 = None;
        let mut max2 = None;
        let mut max3 = None;
        for num in &nums {
            if max1.is_none() || (max1.is_some() && *num >= *(max1.as_ref().unwrap())) {
                if max1.is_none() || (max1.is_some() && *num > *(max1.as_ref().unwrap())) {
                    max3 = max2;
                    max2 = max1;
                }
                max1 = Some(*num);
            }else if max2.is_none() || (max2.is_some() && *num >= *(max2.as_ref().unwrap())) {
                if max2.is_none() || (max2.is_some() && *num > *(max2.as_ref().unwrap())) {
                    max3 = max2;
                }
                max2 = Some(*num);
            }else if max3.is_none() || (max3.is_some() && *num >= *(max3.as_ref().unwrap())) {
                max3 = Some(*num);
            }
        }
        
        if max3.is_some() {
            max3.unwrap()
        }else{
            max1.unwrap()
        }
    }
}
