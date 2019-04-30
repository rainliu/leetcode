impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        let s = s.as_bytes();
        let mut begin = 0;
        let mut end = 0;
        for pos in 0..s.len() {
            let m = Self::expandCentre(s, pos as i32, pos as i32 + 1);
            let c = Self::expandCentre(s, pos as i32 - 1, pos as i32 +1);
            if m>c && m > end-begin {
                begin = pos + 1 - m/2;
                end = pos + 1 + m/2;
            }else if c > end-begin {
                begin = pos - c/2;
                end = pos + c/2 + 1;
            }
        }
        String::from_utf8(s[begin..end].to_vec()).unwrap()
    }
    
    fn expandCentre(s:&[u8], i: i32, j: i32) -> usize {
        let mut i = i;
        let mut j = j;
        let mut l = (j-i)/2;
        while i>=0 && j<s.len() as i32 && s[i as usize] == s[j as usize] {
            i -= 1;
            j += 1;
            l += 2;
        }
        l as usize
    }
}
