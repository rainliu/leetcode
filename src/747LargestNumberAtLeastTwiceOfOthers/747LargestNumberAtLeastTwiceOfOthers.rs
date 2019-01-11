impl Solution {
    pub fn dominant_index(nums: Vec<i32>) -> i32 {
        let mut largest = None;
        let mut second = None;
        let mut index = 0;
        for i in 0..nums.len() {
            let num = nums[i];
            if largest.is_none() || (largest.is_some() && num >= *largest.as_ref().unwrap()) {
                if largest.is_some() && num > *largest.as_ref().unwrap() {
                    second = largest;
                }
                largest = Some(num);
                index = i;
            }else if second.is_none() || (second.is_some() && num >= *second.as_ref().unwrap()) {
                second = Some(num);
            }
        }
        if second.is_none() || *largest.as_ref().unwrap() >= 2*(*second.as_ref().unwrap()) {
            index as i32
        }else{
            -1
        }
    }
}
