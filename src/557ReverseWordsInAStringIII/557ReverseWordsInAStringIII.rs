impl Solution {
    pub fn reverse_words(s: String) -> String {
        let mut s = s.into_bytes();
        let n = s.len();
        let mut i = 0;
        let mut j = 0;
        while j < n {
            while j < n && s[j]==' ' as u8 {j+=1;}
            i = j;
            while j < n && s[j]!=' ' as u8 {j+=1;}
            if i < j {
                s[i..j].reverse();
            }
        }
        String::from_utf8(s).unwrap()
    }
}
