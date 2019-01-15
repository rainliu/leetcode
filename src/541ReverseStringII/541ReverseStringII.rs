impl Solution {
    pub fn reverse_str(s: String, k: i32) -> String {
        let mut s = s.into_bytes();
        let n = s.len();
        for i in (0..n).step_by(2*k as usize) {
            let l = std::cmp::min(i+k as usize,n);
            s[i..l].reverse();
        }
        String::from_utf8(s).unwrap()
    }
}
