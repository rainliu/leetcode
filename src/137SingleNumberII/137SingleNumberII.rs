impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        let mut bits = vec![0;32];
        for num in nums {
            for i in 0..32{
                bits[i]+=(num>>i)&0x1;
            }
        }
        let mut n = 0;
        for i in 0..32{
            n|=((bits[i]%3)<<i);
        }
        return n;
    }
}
