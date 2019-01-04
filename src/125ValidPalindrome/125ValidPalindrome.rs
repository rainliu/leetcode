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

impl FasterSolution {
    pub fn is_palindrome(s: String) -> bool {
        let mut iter = s.chars();
        let mut buf = String::new();
        while let Some(c) = iter.next() {
            if c.is_alphanumeric() {
                buf.push(c.to_ascii_lowercase());
            }
        }
        iter = buf.chars();
        while let (Some(p), Some(q)) = (iter.next(), iter.next_back()) {
            if p != q {
                return false;
            }
        }
        true
    }
}
