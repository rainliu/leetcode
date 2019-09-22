impl Solution {
    pub fn find_duplicate(nums: Vec<i32>) -> i32 {
        let (mut first, mut second) = (nums[0], nums[nums[0] as usize]);
        while first != second {
            second = nums[nums[second as usize] as usize];
            first = nums[first as usize];
        }
        second = 0;
        while first != second {
            first = nums[first as usize];
            second = nums[second as usize];
        }
        first
    }
}
