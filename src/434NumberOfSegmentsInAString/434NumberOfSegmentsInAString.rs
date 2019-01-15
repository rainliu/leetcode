impl Solution {
    pub fn count_segments(s: String) -> i32 {
        let chars = s.into_bytes();
        let n = chars.len();
        let mut i = 0;
        let mut j = 0;
        while j < n {
            while j < n && chars[j]==' ' as u8 {j+=1;}
            if    j < n && chars[j]!=' ' as u8 {i+=1;}
            while j < n && chars[j]!=' ' as u8 {j+=1;}
        }
        i
    }
}
