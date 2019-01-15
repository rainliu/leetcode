impl Solution {
    pub fn detect_capital_use(word: String) -> bool {
        let chars = word.into_bytes();
        let n = chars.len();
        let mut i = 0;
        if chars[n-1] < 'a' as u8 {
            while i < n-1 && chars[i] <  'a' as u8 {i+=1;}
        }else{
            i = 1;
            while i < n-1 && chars[i] >= 'a' as u8 {i+=1;}
        }
        i>=n-1
    }
}
