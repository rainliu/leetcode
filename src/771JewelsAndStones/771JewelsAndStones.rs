impl Solution {
    pub fn num_jewels_in_stones(j: String, s: String) -> i32 {
        let mut jewels = vec![0; 128];
        for c in j.into_bytes() {
            jewels[c as usize] = 1;
        }
        let mut result = 0;
        for c in s.into_bytes() {
            result += jewels[c as usize];
        }
        result
    }
}
