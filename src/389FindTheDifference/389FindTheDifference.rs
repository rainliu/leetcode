impl Solution {
    pub fn find_the_difference(s: String, t: String) -> char {
        let mut count = vec![0; 26];
        for c in s.into_bytes() {
            count[(c-'a' as u8) as usize] += 1;
        }
        for c in t.into_bytes() {
            let p = (c-'a' as u8) as usize;
            if count[p] == 0 {
                return c as char;
            }else{
                count[p] -= 1;
            }
        }
        'a'
    }
}
