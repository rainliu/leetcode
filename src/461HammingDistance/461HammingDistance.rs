impl Solution {
    pub fn hamming_distance(x: i32, y: i32) -> i32 {
        let z = x^y;
        let mut count = 0;
        for i in 0..32{
            count += (z>>i)&0x1
        }
        count
    }
}
