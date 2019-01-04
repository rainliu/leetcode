impl Solution {
    pub fn is_palindrome(s: String) -> bool {
        if s.len() == 0 {return true;}
        let s = s.to_lowercase();
        let b = s.as_bytes();
        let mut i = 0;
        let mut j = b.len() - 1;
        while i<j && !(b[i] as char).is_alphanumeric() {
            i += 1;
        }
        while i<j && !(b[j] as char).is_alphanumeric() {
            j -= 1;
        }
        while i<j {
            if b[i] != b[j] {
                return false;
            }
            i += 1;
            j -= 1;
            while i<j && !(b[i] as char).is_alphanumeric() {
                i += 1;
            }
            while i<j && !(b[j] as char).is_alphanumeric() {
                j -= 1;
            }
        }
        true
    }
    
}
