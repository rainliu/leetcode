impl Solution {
    pub fn is_one_bit_character(bits: Vec<i32>) -> bool {
        let n = bits.len();
        let mut i = 0;
        while i < n {
            if i==n-1 && bits[i]==0 {return true;}
            i += bits[i] as usize + 1;
        }
        false
    }
}
