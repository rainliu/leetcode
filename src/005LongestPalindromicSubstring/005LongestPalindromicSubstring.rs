impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        let s = s.as_bytes();
        let mut begin = 0;
        let mut end = 0;
        for pos in 0..s.len() {
            let m = Self::findMirror(s, pos);
            let c = Self::findCentre(s, pos);
            if m*2>c && m*2 > end-begin {
                begin = pos + 1 - m;
                end = pos + 1 + m;
            }else if c > end-begin {
                begin = pos - c/2;
                end = pos + c/2 + 1;
            }
        }
        String::from_utf8(s[begin..end].to_vec()).unwrap()
    }
    
    fn findMirror(s:&[u8], pos: usize) -> usize {
        let mut i = pos as i32;
        let mut j = pos as i32 +1;
        let mut l = 0;
        while i>=0 && j<s.len() as i32 && s[i as usize] == s[j as usize] {
            i -= 1;
            j += 1;
            l += 1;
        }
        l
    }
    
    fn findCentre(s:&[u8], pos: usize) -> usize {
        let mut i = pos as i32 -1;
        let mut j = pos as i32 +1;
        let mut l = 1;
        while i>=0 && j<s.len() as i32 && s[i as usize] == s[j as usize] {
            i -= 1;
            j += 1;
            l += 2;
        }
        l
    }
}
