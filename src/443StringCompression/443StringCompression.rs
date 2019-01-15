impl Solution {
    pub fn compress(chars: &mut Vec<char>) -> i32 {
        let n = chars.len();
        let mut i = 0;
        let mut j = 0;
        let mut k = 0;
        while j < n {
            while j < n && chars[j]==chars[i] {j+=1;} 
            chars[k] = chars[i];
            k += 1;
            let c = j-i;
            if c > 1 {
                let cstr = c.to_string();
                let mut iter = cstr.chars();
                while let Some(ch) = iter.next() {
                    chars[k] = ch;
                    k += 1;
                }
            }
            i = j;
        }
        k as i32
    }
}
