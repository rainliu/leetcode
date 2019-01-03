impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {
        let s = s.trim_end();
        let mut chars = s.chars().rev();
        let mut length = 0;
        while let Some(ch) = chars.next() {
            if ch == ' ' {
                break;
            }    
            length += 1;
        }
        
        length
    }
}
